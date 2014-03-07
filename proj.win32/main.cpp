#include "Config\Config.h"

#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;



int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShOw)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("HobbyRPG");
	eglView->setFrameSize(Config::getInstance().getDesignWidth(), Config::getInstance().getDesignHeight());


    return CCApplication::sharedApplication()->run();
}
