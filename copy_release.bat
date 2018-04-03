MD ".\Release\Visual C++ Project"

COPY /Y .\APPTemplate\APPTemplate.vcxproj .\APPTemplate.vcxproj
COPY /Y .\CONTemplate\CONTemplate.vcxproj .\CONTemplate.vcxproj
COPY /Y .\DLLTemplate\DLLTemplate.vcxproj .\DLLTemplate.vcxproj

FixTool .\APPTemplate.vcxproj
FixTool .\CONTemplate.vcxproj
FixTool .\DLLTemplate.vcxproj

DEL ".\Release\Visual C++ Project\APPTemplate.zip"
7z a -tzip ".\Release\Visual C++ Project\APPTemplate.zip" .\APPTemplate\__TemplateIcon.ico .\APPTemplate.vcxproj .\APPTemplate\APPTemplate.vcxproj.filters .\APPTemplate\main.cc .\APPTemplate\MyTemplate.vstemplate

DEL ".\Release\Visual C++ Project\CONTemplate.zip"
7z a -tzip ".\Release\Visual C++ Project\CONTemplate.zip" .\CONTemplate\__TemplateIcon.ico .\CONTemplate.vcxproj .\CONTemplate\CONTemplate.vcxproj.filters .\CONTemplate\main.cc .\CONTemplate\MyTemplate.vstemplate

DEL ".\Release\Visual C++ Project\DLLTemplate.zip"
7z a -tzip ".\Release\Visual C++ Project\DLLTemplate.zip" .\DLLTemplate\__TemplateIcon.ico .\DLLTemplate.vcxproj .\DLLTemplate\DLLTemplate.vcxproj.filters .\DLLTemplate\main.cc .\DLLTemplate\MyTemplate.vstemplate

DEL .\APPTemplate.vcxproj
DEL .\CONTemplate.vcxproj
DEL .\DLLTemplate.vcxproj


COPY /Y ".\Release\Visual C++ Project\APPTemplate.zip" "%HOMEDRIVE%%HOMEPATH%\Documents\Visual Studio 2017\Templates\ProjectTemplates\Visual C++ Project\APPTemplate.zip"
COPY /Y ".\Release\Visual C++ Project\CONTemplate.zip" "%HOMEDRIVE%%HOMEPATH%\Documents\Visual Studio 2017\Templates\ProjectTemplates\Visual C++ Project\CONTemplate.zip"
COPY /Y ".\Release\Visual C++ Project\DLLTemplate.zip" "%HOMEDRIVE%%HOMEPATH%\Documents\Visual Studio 2017\Templates\ProjectTemplates\Visual C++ Project\DLLTemplate.zip"

PAUSE