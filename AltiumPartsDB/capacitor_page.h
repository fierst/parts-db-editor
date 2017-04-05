#ifndef CAPACITOR_PAGE_H
#define CAPACITOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class capacitor_page;
}

class capacitor_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit capacitor_page(QWidget *parent = 0);
  ~capacitor_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::capacitor_page *ui;
}

#endif // CAPACITOR_PAGE_H