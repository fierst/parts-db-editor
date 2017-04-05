#ifndef IC_PAGE_H
#define IC_PAGE_H

#include <QWizardPage>

namespace Ui {
  class ic_page;
}

class ic_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit ic_page(QWidget *parent = 0);
  ~ic_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::ic_page *ui;
}

#endif // IC_PAGE_H