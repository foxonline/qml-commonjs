#ifndef COMMONJS_H
#define COMMONJS_H

#include <QObject>
#include <QtQml>

class CommonJS : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(CommonJS)
    Q_PROPERTY(QJSValue cache READ cache)

public:
    explicit CommonJS(QQmlEngine *engine, QJSEngine *scriptEngine);

    Q_INVOKABLE QJSValue require(QString url);
    Q_INVOKABLE QString resolve(QString url, QString base = "");
    QJSValue cache() { return m_cache; }

    // Pseudo-private function that is only public
    // so that javascript code will have access to them
    Q_INVOKABLE QString __loadFile(QString url);

protected:
    QJSValue m_cache;
    QString m_requireTemplate;
    QQmlEngine *m_engine;
    QJSEngine *m_scriptEngine;
};

#endif // COMMONJS_H

