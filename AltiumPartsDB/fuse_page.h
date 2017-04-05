#ifndef FUSE_PAGE_H
#define FUSE_PAGE_H

#include <QWizardPage>

namespace Ui {
  class fuse_page;
}

class fuse_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit fuse_page(QWidget *parent = 0);
  ~fuse_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::fuse_page *ui;
}

#endif // FUSE_PAGE_H