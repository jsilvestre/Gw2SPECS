#include "configurator.h"
#include "ui_configurator.h"
#include "settings.h"
#include "mainwindow.h"

using namespace GW2;

Configurator::Configurator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configurator)
{
    ui->setupUi(this);

    // hide not used settings:
    ui->checkBoxCDamage->setVisible(false);
    ui->checkBoxCDPS->setVisible(false);
    ui->checkBoxCPerDmg->setVisible(false);
    ui->checkBoxActivity->setVisible(false);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    // Set version
    ui->labelVersion->setText(Settings::s_Product);

    Settings::ReadSettings(ui->checkBoxProfColors);
    Settings::ReadSettings(ui->checkBoxName);
    Settings::ReadSettings(ui->checkBoxDamage);
    Settings::ReadSettings(ui->checkBoxDPS);
    Settings::ReadSettings(ui->checkBoxCDamage);
    Settings::ReadSettings(ui->checkBoxCPerDmg);
    Settings::ReadSettings(ui->checkBoxCDPS);
    Settings::ReadSettings(ui->checkBox5sDPS);
    Settings::ReadSettings(ui->professionComboBox);
    Settings::ReadSettings(ui->checkBoxPosition);
    Settings::ReadSettings(ui->checkBoxPerDmg);
    Settings::ReadSettings(ui->checkBoxActivity);

    Settings::ReadSettings(ui->checkBoxGraphShow);
    Settings::ReadSettings(ui->checkBoxGraphRealDPS);
    Settings::ReadSettings(ui->checkBoxGraph5sDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgCDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgGroupDPS);

    Settings::ReadSettings(ui->comboBoxScreenshots);
    Settings::ReadSettings(ui->comboBoxUpdates);
    Settings::ReadSettings(ui->comboBoxSecondsInCombat);
    Settings::ReadSettings(ui->comboBoxConsideredLines);

}

Configurator::~Configurator()
{
    Settings::WriteSettings(ui->checkBoxProfColors);
    Settings::WriteSettings(ui->checkBoxName);
    Settings::WriteSettings(ui->checkBoxDamage);
    Settings::WriteSettings(ui->checkBoxDPS);
    Settings::WriteSettings(ui->checkBoxCDamage);
    Settings::WriteSettings(ui->checkBoxCPerDmg);
    Settings::WriteSettings(ui->checkBoxCDPS);
    Settings::WriteSettings(ui->checkBox5sDPS);
    Settings::WriteSettings(ui->professionComboBox);
    Settings::WriteSettings(ui->checkBoxPosition);
    Settings::WriteSettings(ui->checkBoxPerDmg);
    Settings::WriteSettings(ui->checkBoxActivity);

    Settings::WriteSettings(ui->checkBoxGraphShow);
    Settings::WriteSettings(ui->checkBoxGraphRealDPS);
    Settings::WriteSettings(ui->checkBoxGraph5sDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgCDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgGroupDPS);

    Settings::WriteSettings(ui->comboBoxScreenshots);
    Settings::WriteSettings(ui->comboBoxUpdates);
    Settings::WriteSettings(ui->comboBoxSecondsInCombat);
    Settings::WriteSettings(ui->comboBoxConsideredLines);
    delete ui;
}

void Configurator::RestoreDefaults()
{
    ui->comboBoxScreenshots->setCurrentIndex(0);
    ui->comboBoxUpdates->setCurrentIndex(0);
    ui->comboBoxSecondsInCombat->setCurrentIndex(0);
    ui->comboBoxConsideredLines->setCurrentIndex(0);
}

// Give movement access to MainWindow
void Configurator::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

// Give movement access to MainWindow
void Configurator::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

