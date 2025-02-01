#ifndef FFILE_H
#define FFILE_H

#include "ffile_global.h"

#include <QObject>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <algorithm>
#include <QFileInfo>
#include <fstream>

namespace fs = std::filesystem;


class FFILE_EXPORT Ffile
{
public:
    Ffile();
    void findFiles(const fs::path& directoryPath,
                   const std::string& searchPattern,
                   std::vector<std::string>& fileList);
    //QString  loadTextFromFile(const QString &filePath);
    QString  loadTextFromFile(const fs::path&filePath);
    QString findPatternStringInFilename(const std::string& searchPattern,
                                        bool &exit);


};

#endif // FFILE_H
