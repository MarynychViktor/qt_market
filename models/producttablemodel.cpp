#include "producttablemodel.h"

#include <QAbstractTableModel>
#include <QDebug>
#include <QModelIndex>
#include <QString>
#include <QString>

ProductTableModel::ProductTableModel()
    : products  {
          new Product(QString("AK-47 factory new"), QString("test/photo"), QString("1_c"), QString("1_i"), QString("Field-tested"), 150.0, 200.0)
//              Product(QString name, QString photo, QString classId, QString instanceId, QString quality, double orderLimit, double sellLimit)
//          new Product("M16 Field tested", 200, 300)
    }
    {
    }

int ProductTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : products.length();
}

int ProductTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ProductTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        auto product = products.at(index.row());

        switch (index.column()) {
            case 0:
                return product->name;
            case 1:
                return product->maxAllowedOrderPrice;
            case 2:
                return product->minAllowedTradePrice;
        }
    }

    return QVariant();
}

Qt::ItemFlags ProductTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant ProductTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {

        switch (section) {
            case 0:
                return "Name";
            case 1:
                return "Order Price";
            case 2:
                return "Sell Price";
        }
    }

    return QVariant();
}

bool ProductTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        qInfo("Edit model fired");
        auto product = products.at(index.row());
        switch (index.column()) {
            case 0:
                product->name = QString(value.toString());
                break;
            case 1:
                product->maxAllowedOrderPrice = value.toDouble();
                break;
            case 2:
                product->minAllowedTradePrice = value.toDouble();
                break;
        }

        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

void ProductTableModel::sort(int column, Qt::SortOrder order)
{

    qInfo("Sorting");
    std::sort(products.begin(), products.end(), [column, order](const Product* a, const Product* b) {
            switch (column) {
                case 0:
                    if (order == Qt::AscendingOrder) {
                      return a->name > b->name;
                    } else {
                       return a->name < b->name;
                    }

                case 1:
                    if (order == Qt::AscendingOrder) {
                      return a->maxAllowedOrderPrice > b->maxAllowedOrderPrice;
                    } else {
                       return a->maxAllowedOrderPrice < b->maxAllowedOrderPrice;
                    }
                case 2:
                if (order == Qt::AscendingOrder) {
                  return a->minAllowedTradePrice > b->minAllowedTradePrice;
                } else {
                   return a->minAllowedTradePrice < b->minAllowedTradePrice;
                }
            default:
                qInfo("NOT MATCHED");
            }
          });

   emit dataChanged(createIndex(0, 0), createIndex(rowCount(), columnCount()));
}
