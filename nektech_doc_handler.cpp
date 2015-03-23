/*
 * nektech_doc_handler.cpp - nektechTextEditor
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
 
#include "nektech_doc_handler.h"
#include <QtGui/QTextDocument>
#include <QtGui/QTextCursor>
#include <QtCore/QFileInfo>

NEKTech_Doc_Handler::NEKTech_Doc_Handler()
    : m_target(0)
    , m_doc(0)
    , m_cursorPosition(-1)
    , m_selectionStart(0)
    , m_selectionEnd(0)
{
}

void NEKTech_Doc_Handler::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_target = target;
    if (!m_target)
        return;

    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            m_doc = qqdoc->textDocument();
    }
    emit targetChanged();
}

void NEKTech_Doc_Handler::setFileUrl(const QUrl &arg)
{
    if (m_fileUrl != arg) {
        m_fileUrl = arg;
        QString fileName = QQmlFile::urlToLocalFileOrQrc(arg);
        if (QFile::exists(fileName)) {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly)) {
                QByteArray data = file.readAll();
                QTextCodec *codec = QTextCodec::codecForHtml(data);
                setText(codec->toUnicode(data));
                if (m_doc)
                    m_doc->setModified(false);
                if (fileName.isEmpty())
                    m_documentTitle = QStringLiteral("untitled.txt");
                else
                    m_documentTitle = QFileInfo(fileName).fileName();

                emit textChanged();
                emit documentTitleChanged();

            }
        }
        emit fileUrlChanged();
    }
}

QString NEKTech_Doc_Handler::documentTitle() const
{
    return m_documentTitle;
}

void NEKTech_Doc_Handler::setDocumentTitle(QString arg)
{
    if (m_documentTitle != arg) {
        m_documentTitle = arg;
        emit documentTitleChanged();
    }
}

void NEKTech_Doc_Handler::setText(const QString &arg)
{
    if (m_text != arg) {
        m_text = arg;
        emit textChanged();
    }
}

QUrl NEKTech_Doc_Handler::fileUrl() const
{
    return m_fileUrl;
}

QString NEKTech_Doc_Handler::text() const
{
    return m_text;
}

void NEKTech_Doc_Handler::setCursorPosition(int position)
{
    if (position == m_cursorPosition)
        return;

    m_cursorPosition = position;

}

QTextCursor NEKTech_Doc_Handler::textCursor() const
{
    QTextCursor cursor = QTextCursor(m_doc);
    if (m_selectionStart != m_selectionEnd) {
        cursor.setPosition(m_selectionStart);
        cursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
    } else {
        cursor.setPosition(m_cursorPosition);
    }
    return cursor;
}

void NEKTech_Doc_Handler::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
}

void NEKTech_Doc_Handler::setSelectionStart(int position)
{
    m_selectionStart = position;
}

void NEKTech_Doc_Handler::setSelectionEnd(int position)
{
    m_selectionEnd = position;
}
