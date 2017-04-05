#ifndef NEW_PART_WIZARD_H
#define NEW_PART_WIZARD_H

#include <QWizard>

class new_part_wizard : public QWizard
{
    Q_OBJECT

public:
    new_part_wizard(QWidget *parent = 0);

    void accept() override;

};

class part_params_page : public QWizardPage
{
    Q_OBJECT

public:
    part_params_page(QWidget *parent = 0);

};

class

#endif // NEW_PART_WIZARD_H
