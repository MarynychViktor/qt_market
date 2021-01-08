#include "ProductTableModel.h"
#include "../Jobs/UpdateTradePricesJob.h"
#include "../Infrastructure/DI/ServiceLocator.h"
#include "../Services/ProductManager.h"

#include <QAbstractTableModel>
#include <QString>


ProductTableModel::~ProductTableModel()
{
}

int ProductTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : products.length();
}

int ProductTableModel::columnCount(const QModelIndex &parent) const
{
    return 6;
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
                return QString::number(product->minAllowedTradePrice, 'g', 10);
            case 3:
                return product->quality;
            case 4:
                return product->classId;
            case 5:
                return product->instanceId;
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
            case 3:
                return "Quality";
            case 4:
                return "Class Id";
            case 5:
                return "Instance Id";
        }
    }

    return QVariant();
}

bool ProductTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        auto serviceLocator = ServiceLocator::Instance();
        auto productManager = serviceLocator->GetService<ProductManager>();
        auto product = products.at(index.row());
        switch (index.column()) {
            case 1:
                product->maxAllowedOrderPrice = value.toDouble();
                productManager->updateMaxAllowedOrderPrice(product, value.toInt());
                break;
            case 2:
                product->minAllowedTradePrice = value.toDouble();
                productManager->updateMinAllowedTradePrice(product, value.toInt());
                break;
            default:
                return false;
        }

        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

void ProductTableModel::sort(int column, Qt::SortOrder order)
{
    std::sort(products.begin(), products.end(), [column, order](shared_ptr<Product> a, shared_ptr<Product> b) {
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
                    return true;
            }
          });

   emit dataChanged(createIndex(0, 0), createIndex(rowCount(), columnCount()));
}

void ProductTableModel::setProducts(QList<shared_ptr<Product>> updatedProducts) {
    products = updatedProducts;
    emit dataChanged(createIndex(0, 0), createIndex(rowCount(), columnCount()));
}
