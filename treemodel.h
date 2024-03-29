
#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class TreeNode;
class QTextStream;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(const QString &data, QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    Qt::DropActions supportedDropActions() const Q_DECL_OVERRIDE;
    QStringList mimeTypes() const Q_DECL_OVERRIDE;
    QMimeData *mimeData(const QModelIndexList &indexes) const Q_DECL_OVERRIDE;
    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex & parent) Q_DECL_OVERRIDE;

    TreeNode *getNode(const QModelIndex &index) const;
    bool removeRows(int position, int rows, const QModelIndex &parent) Q_DECL_OVERRIDE;
    bool insertRows(int position, int rows, const QModelIndex &parent) Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QByteArray getModelData();
private:
    void addChildData(TreeNode *node, QTextStream &stream, int tabsCount);
    TreeNode * nodeForIndex(const QModelIndex &index) const;
    void removeNode(TreeNode *node);
    void setupModelData(const QStringList &lines, TreeNode *parent);

    TreeNode *m_rootNode;
};

#endif // TREEMODEL_H






















