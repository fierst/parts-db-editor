#ifndef FILTER_PAGE_H
#define FILTER_PAGE_H

#include <QWizardPage>

namespace Ui {
  class filter_page;
}

class filter_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit filter_page(QWidget *parent = 0);
  ~filter_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::filter_page *ui;
}

#endif // FILTER_PAGE_H