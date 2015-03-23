#ifndef NEKTECH_DOC_HANDLER_H
#define NEKTECH_DOC_HANDLER_H
/*
 * nektech_doc_handler.h - nektechTextEditor
 *
 * Copyright (C) NEK Tech 2013
 * Developers V1.0:  	Pankaj Saraf
 *			            Jitendra Khasdev
 *                      Pooja Shukla
 *                      Akshay Rastogi
 *                      Poovika Ujjaini
 * Copyright (C) NEK Tech 2015
 *
 * Author and Architect: Pankaj Saraf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms and conditions of NEK Tech.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <QQuickTextDocument>

#include <QtGui/QTextCharFormat>
#include <QtCore/QTextCodec>

#include <qqmlfile.h>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE


class NEKTech_Doc_Handler: public QObject
{
    Q_OBJECT

    Q_ENUMS(HAlignment)

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition NOTIFY cursorPositionChanged)
    Q_PROPERTY(int selectionStart READ selectionStart WRITE setSelectionStart NOTIFY selectionStartChanged)
    Q_PROPERTY(int selectionEnd READ selectionEnd WRITE setSelectionEnd NOTIFY selectionEndChanged)

    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString documentTitle READ documentTitle WRITE setDocumentTitle NOTIFY documentTitleChanged)

public:
    NEKTech_Doc_Handler();
    QQuickItem *target() { return m_target; }

    void setTarget(QQuickItem *target);

    void setCursorPosition(int position);
    void setSelectionStart(int position);
    void setSelectionEnd(int position);

    int cursorPosition() const { return m_cursorPosition; }
    int selectionStart() const { return m_selectionStart; }
    int selectionEnd() const { return m_selectionEnd; }

    QUrl fileUrl() const;
    QString text() const;

    QString documentTitle() const;

public Q_SLOTS:
    void setFileUrl(const QUrl &arg);
    void setText(const QString &arg);

    void setDocumentTitle(QString arg);

Q_SIGNALS:
    void targetChanged();
    void cursorPositionChanged();
    void selectionStartChanged();
    void selectionEndChanged();

    void fileUrlChanged();

    void textChanged();
    void documentTitleChanged();

private:
    QTextCursor textCursor() const;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    QQuickItem *m_target;
    QTextDocument *m_doc;

    int m_cursorPosition;
    int m_selectionStart;
    int m_selectionEnd;

    QUrl m_fileUrl;
    QString m_text;
    QString m_documentTitle;
};

#endif // NEKTECH_DOC_HANDLER_H
