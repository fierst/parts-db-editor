#ifndef OPTOELECTRONIC_PAGE_H
#define OPTOELECTRONIC_PAGE_H

#include <QWizardPage>

namespace Ui {
  class optoelectronic_page;
}

class optoelectronic_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit optoelectronic_page(QWidget *parent = 0);
  ~optoelectronic_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::optoelectronic_page *ui;
}

#endif // OPTOELECTRONIC_PAGE_H