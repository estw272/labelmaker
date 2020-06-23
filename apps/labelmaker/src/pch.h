#pragma once
#ifndef _PCH_H_232398
#define _PCH_H_232398

#pragma warning(push, 0)

#define WIN32_LEAN_AND_MEAN

//basic c++ stuff
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>
#include <filesystem>
#include <algorithm>
#include <mutex>
#include <string_view>
#include <fstream>
#include <codecvt>

//QT stuff
#include <QtWidgets/QApplication>
#include <QVariant>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QCloseEvent>
#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QFileDialog>
#include <QKeySequence>
#include <QShortcut>
#include <QAction>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QPainter>
#include <QImage>

//cereal
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/types/set.hpp"
#include "cereal/access.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/types/optional.hpp"

//protobuf
#include "prototagscache.pb.h"

#pragma warning(pop)

#endif
