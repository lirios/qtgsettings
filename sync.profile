%modules = ( # path to module name map
    "QtGSettings" => "$basedir/src/gsettings",
);
%moduleheaders = ( # restrict the module headers to those found in relative path
    "qtgsettingsglobal.h"
);
%classnames = (
    "qgsettings.h" => "QGSettings",
);
