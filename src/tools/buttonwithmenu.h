/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef BUTTONWITHMENU_H
#define BUTTONWITHMENU_H

#include <QToolButton>
#include <QAction>
#include <QMenu>
#include <QWheelEvent>

#include "toolbutton.h"

class ButtonWithMenu : public ToolButton
{
    Q_OBJECT
public:
    struct Item {
        QString text;
        QIcon icon;
        QVariant userData;

        Item(const QString &a = QString(), const QIcon &b = QIcon())
        {
            text = a;
            icon = b;
        }

        bool operator==(const Item &a)
        {
            return (a.text == text) && (a.icon.pixmap(16,16).toImage() == icon.pixmap(16,16).toImage());
        }
    };

    explicit ButtonWithMenu(QWidget* parent = 0);
    ~ButtonWithMenu();

    void addItem(const Item &item);
    void addItems(const QList<Item> &items);
    void removeItem(const Item &item);
    void setActiveItem(const Item &item);

    Item* activeItem();

signals:
    void activeItemChanged(const ButtonWithMenu::Item &item);
    void itemAdded(const ButtonWithMenu::Item &item);
    void itemRemoved(const ButtonWithMenu::Item &item);

public slots:

private slots:
    void setCurrentItem();

private:
    void wheelEvent(QWheelEvent *event);
    void generateMenu();

    QMenu* m_menu;
    QList<Item> m_items;
    Item* m_currentItem;

};

Q_DECLARE_METATYPE(ButtonWithMenu::Item)

#endif // BUTTONWITHMENU_H