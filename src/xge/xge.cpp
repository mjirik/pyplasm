#include <xge/xge.h>
#include <xge/glcanvas.h>

#define DONT_SET_USING_JUCE_NAMESPACE 1
#include <juce_2_0/juce.h>

///////////////////////////////////////////////////////////////////////////////////////////
class XgeApplication : public juce::JUCEApplication
{
public:
#if PYPLASM_APPLE
  JUCE_AUTORELEASEPOOL
#endif
  
  XgeApplication                                  ()                                 {}
  ~XgeApplication                                 ()                                 {}
  void                 shutdown                   ()                                 {}
  const juce::String   getApplicationName         ()                                 {return "PyPlasm GLCanvas";}
  const juce::String   getApplicationVersion      ()                                 {return "1.0";}
  bool                 moreThanOneInstanceAllowed ()                                 {return true;}
  void                 anotherInstanceStarted     (const juce::String&)              {}
  void                 initialise                 (const juce::String& commandLine)  {}
};

static SmartPointer<XgeApplication> app;

#if PYPLASM_APPLE
namespace juce
{
  void initialiseNSApplication();
};
#endif


//////////////////////////////////////////////////////////////////
void XgeModule::init()
{
  if (!app)
  {
	  Log::printf("XgeModule::init\n");
    
#if PYPLASM_APPLE
    juce::initialiseNSApplication();
#endif

    juce::initialiseJuce_GUI();
    Log::printf("XgeModule::init_step1\n");
    juce::JUCEApplication::createInstance = (juce::JUCEApplication::CreateInstanceFunction)-1;//need not to be 0 
    Log::printf("XgeModule::init_step2\n");
    app=SmartPointer<XgeApplication>(new XgeApplication());
    Log::printf("XgeModule::init_step3\n");
    app->initialiseApp("dummy");
    Log::printf("XgeModule::init_step4\n");
#if !PYPLASM_TRAVIS
// canvas cause fail on travis-ci
    GLCanvas::setShared(SmartPointer<GLCanvas>(new GLCanvas));
#endif
    Log::printf("XgeModule::init_finished\n");
  }
}

//////////////////////////////////////////////////////////////////
void XgeModule::shutdown()
{
  if (app)
  {
    Log::printf("XgeModule::shutdown\n");
    GLCanvas::setShared(SmartPointer<GLCanvas>());
    app->shutdown();
    app.reset();
    juce::shutdownJuce_GUI();
  }
}
