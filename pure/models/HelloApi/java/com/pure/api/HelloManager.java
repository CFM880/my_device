package com.pure.api;

import android.os.RemoteException;
import android.os.ServiceManager;
import android.pure.IHelloService;

public class HelloManager {
    private static HelloManager mInstance = null;
    public static HelloManager getInstance() {
        if(null == mInstance) {
            mInstance = new HelloManager();
        }
        return mInstance;
    }

    private IHelloService mService = null;

    private HelloManager() {
        mService = IHelloService.Stub.asInterface(ServiceManager.getService("HelloService"));
    }

    public void sayHello(String name) {
        try {
            mService.hello(name);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
