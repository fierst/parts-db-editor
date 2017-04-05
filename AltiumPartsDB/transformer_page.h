#ifndef TRANSFORMER_PAGE_H
#define TRANSFORMER_PAGE_H

#include <QWizardPage>

namespace Ui {
  class transformer_page;
}

class transformer_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit transformer_page(QWidget *parent = 0);
  ~transformer_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::transformer_page *ui;
}

#endif // TRANSFORMER_PAGE_H