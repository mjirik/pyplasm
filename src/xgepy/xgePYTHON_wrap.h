/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.0
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_xgepy_WRAP_H_
#define SWIG_xgepy_WRAP_H_

#include <map>
#include <string>


class SwigDirector_GLCanvas : public GLCanvas, public Swig::Director {

public:
    SwigDirector_GLCanvas(PyObject *self);
    virtual ~SwigDirector_GLCanvas();
    virtual void setOctree(std::shared_ptr< Octree > octree);
    virtual bool makeCurrent();
    virtual void doneCurrent();
    virtual void clearScreen(bool ClearColor = true, bool ClearDepth = true);
    virtual void setViewport(int x, int y, int width, int height);
    virtual void setProjectionMatrix(Mat4f mat);
    virtual void setModelviewMatrix(Mat4f mat);
    virtual void setDefaultLight(Vec3f pos, Vec3f dir);
    virtual void pushModelviewMatrix(Mat4f mat, bool AccumulateWithCurrent = true);
    virtual void popModelviewMatrix();
    virtual void pushProjectionMatrix(Mat4f mat, bool AccumulateWithCurrent = true);
    virtual void popProjectionMatrix();
    virtual void setDepthTest(bool value);
    virtual void setDepthWrite(bool vaue);
    virtual void setPolygonMode(int value);
    virtual void setPointSize(float value);
    virtual void setLineWidth(float value);
    virtual void setPolygonOffset(float value);
    virtual void renderBatch(std::shared_ptr< Batch > batch);
    virtual void renderOpenGL();
    virtual void redisplay();
    virtual bool onKeyboard(int key, int x, int y);
    virtual void onMouseDown(int button, int x, int y);
    virtual void onMouseMove(int button, int x, int y);
    virtual void onMouseUp(int button, int x, int y);
    virtual void onMouseWheel(int delta);
    virtual void onResize(int width, int height);
    virtual void close();
    virtual void runLoop();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool val) const {
      swig_inner[swig_protected_method_name] = val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class GLCanvas doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[33];
#endif

};


#endif
