#ifndef CURVESXYEDITOR_H
#define CURVESXYEDITOR_H

#include <QDialog>
#include "dashboard/elements/plot_xy.h"
#include "ui/propertieswidget.h"

namespace Ui {
class QTBCurvesXYEditor;
}

class QTBCurvesXYEditor : public QDialog
{
    Q_OBJECT

public:
    explicit QTBCurvesXYEditor(QTBPlotXY *display, QWidget *parent = nullptr);
    ~QTBCurvesXYEditor() Q_DECL_OVERRIDE;
    void accept() Q_DECL_OVERRIDE;

private slots:
    void updateElement();
    void updateTabs();
    void newParameter();
    void removeParameter();
    void on_listWidget_currentRowChanged(int currentRow);

    void on_rangeComboBox_currentIndexChanged(int index);

    void on_xrangeComboBox_currentIndexChanged(int index);

private:
    Ui::QTBCurvesXYEditor *ui;
    QTBPlotXY *mDisplay;
    QList<PropertiesWidget *> mPropertiesWidgets;
    PropertiesWidget * mXPropertiesWidget;
    QToolButton *mNewParamButton;
    QToolButton *mRemoveParamButton;
};

#endif // CURVESTIMEEDITOR_H
