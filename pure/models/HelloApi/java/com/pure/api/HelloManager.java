package com.pure.api;

import android.os.RemoteException;
import android.os.ServiceManager;
import android.pure.IHelloService;
import android.util.Log;

public class HelloManager {
    private static final String TAG = "HelloManager";
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
            Log.d(TAG, "sayHello " + name);
            mService.hello(name);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
