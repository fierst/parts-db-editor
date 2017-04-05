#ifndef TRANSISTOR_PAGE_H
#define TRANSISTOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class transistor_page;
}

class transistor_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit transistor_page(QWidget *parent = 0);
  ~transistor_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::transistor_page *ui;
}

#endif // TRANSISTOR_PAGE_H