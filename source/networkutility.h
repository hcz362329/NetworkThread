#pragma once

#include <memory>
#include <QString>

class QFile;
class QUrl;
namespace QMTNetwork {

    struct RequestTask;
    enum class RequestType;
    class NetworkUtility
    {
    public:
        //���������ļ�
        static std::unique_ptr<QFile> createAndOpenFile(const QMTNetwork::RequestTask&, QString& errMessage);

        //���������д���ļ�
        static QString createSharedRWFileWin32(const QMTNetwork::RequestTask&, QString& errMessage, qint64 nDefaultFileSize = 0);

        //��ȡ�ļ�������
        static bool readFileContent(const QString& strFilePath, QByteArray& bytes, QString& errMessage);

        //��ȡ�����ļ�������ļ���
        static QString getDownloadFileSaveName(const QMTNetwork::RequestTask&);
        //��ȡ�����ļ������Ŀ¼
        static QString getDownloadFileSaveDir(const QMTNetwork::RequestTask&, QString& errMessage);

        static bool fileExists(QFile *pFile);
        static bool fileOpened(QFile *pFile);
        static bool removeFile(const QString& strFilePath, QString& errMessage);
        static QUrl currentRequestUrl(const QMTNetwork::RequestTask&);

        static const QString getTypeString(const QMTNetwork::RequestType eType);

    private:
        NetworkUtility();
        ~NetworkUtility();
        NetworkUtility(const NetworkUtility &);
        NetworkUtility &operator=(const NetworkUtility &);
    };

    inline bool isHttpProxy(const QString& strScheme) { return (strScheme.compare(QLatin1String("http"), Qt::CaseInsensitive) == 0); }
    inline bool isHttpsProxy(const QString& strScheme) { return (strScheme.compare(QLatin1String("https"), Qt::CaseInsensitive) == 0); }
    inline bool isFtpProxy(const QString& strScheme) { return (strScheme.compare(QLatin1String("ftp"), Qt::CaseInsensitive) == 0); }
}
