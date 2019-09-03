#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include <iostream>
#include <memory>
#include <functional>
#include <map>
#include <QDebug>
#include "dashboard/dashboard_element.h"

using namespace std;

class ElementFactory
{
public:
    static ElementFactory* Instance() {
        static ElementFactory factory;
        return &factory;
    }

    QTBDashboardElement* Create(QString name) {
        QTBDashboardElement* instance = nullptr;

        // find name in the registry and call factory method.
        auto it = elementRegistry.find(name);
        if (it != elementRegistry.end())
            instance = it->second();

        return instance;

    }
    void RegisterElement(QString name,
                         std::function<QTBDashboardElement*(void)> classFactoryFunction,
                         QString iconPath = QString()) {
        // register the class factory function
        elementRegistry[name] = classFactoryFunction;

        if(!elementsName.contains(name))
            elementsName.append(name);

        elementIcons.insert(name, iconPath);
    }

    map<QString, function<QTBDashboardElement*(void)>> elementRegistry;

    QMap<QString, QString> elementIcons;

    QString elementIconPath(QString elementName) {
        if(elementIcons.contains(elementName))
            return elementIcons.value(elementName);
        else {
            return QString();
        }
    }
    QStringList elementsName;
    QStringList getElementsName() const { return elementsName; }
};

template<class T> class ElementRegister {
public:
    ElementRegister(QString elementName, QString elementIconPath = QString()) {
        // register the class factory function
        ElementFactory::Instance()->RegisterElement(elementName,
                                                    [](void) -> QTBDashboardElement * { return new T();},
                                                    elementIconPath);
    }
};

#endif // ELEMENTFACTORY_H
