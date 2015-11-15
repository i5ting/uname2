#include "functions.h"

using v8::FunctionTemplate;

// NativeExtension.cc represents the top level of the module.
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, Nan::New("sysname").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(sysname)).ToLocalChecked());
  
  Nan::Set(target, Nan::New("nodename").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(nodename)).ToLocalChecked());


  Nan::Set(target, Nan::New("release").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(release)).ToLocalChecked());


  Nan::Set(target, Nan::New("version").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(version)).ToLocalChecked());


  Nan::Set(target, Nan::New("machine").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(machine)).ToLocalChecked());

  // Passing target down to the next NAN_MODULE_INIT
  MyObject::Init(target);
}

NODE_MODULE(NativeExtension, InitAll)
