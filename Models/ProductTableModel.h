#ifndef PRODUCTTABLEMODEL_H
#define PRODUCTTABLEMODEL_H

#include <QAbstractTableModel>
#include "Product.h"


class ProductTableModel  : public QAbstractTableModel
{
public:
    ProductTableModel(QList<shared_ptr<Product>> products) : products(products) {};
    ~ProductTableModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    void setProducts(QList<shared_ptr<Product>> updatedProducts);

    QList<shared_ptr<Product>> products;
};

#endif // PRODUCTTABLEMODEL_H
