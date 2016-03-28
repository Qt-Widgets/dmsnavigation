/**
   The MIT License (MIT)

   Copyright (c) 2014 thelostcode

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
   */

#ifndef DMS_NAVIGATION_H
#define DMS_NAVIGATION_H

#include <QWidget>
#include <QStackedWidget>

class QEvent;
class QPaintEvent;
class QMouseEvent;

class DMSNavigationBar;
class DMSNavigation : public QWidget
{
   Q_OBJECT
   Q_ENUMS(HorizontalAlignment)
   Q_PROPERTY(HorizontalAlignment horizonalAlignment READ horizontalAlignment WRITE setHorizontalAlignment)
   Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex)
   Q_PROPERTY(int cound READ count)

public:
   explicit DMSNavigation(QWidget* parent = NULL, Qt::WindowFlags flags = 0);
   ~DMSNavigation();

   int addTab(QWidget* widget, const QString& text);
   int addTab(QWidget* widget, const QIcon& icon, const QString& text);

   int insertTab(int index, QWidget* widget, const QString& text);
   int insertTab(int index, QWidget* widget, const QIcon& icon, const QString& text);

   void removeTab(int index);

   QString tabText(int index) const;
   void setTabText(int index, const QString& text);

   QIcon tabIcon(int index) const;
   void setTabIcon(int index, const QIcon& icon);

   enum HorizontalAlignment { AlignLeft, AlignCenter, AlignRight };

   HorizontalAlignment horizontalAlignment() const;
   void setHorizontalAlignment(HorizontalAlignment alignment);

   int count() const;
   int currentIndex() const;

public slots:
   void setCurrentIndex(int index);

signals:
   void currentChanged(int index);

private:
   Q_DISABLE_COPY(DMSNavigation)

private:
   QStackedWidget stacked;
   DMSNavigationBar* navigation;

};

#endif