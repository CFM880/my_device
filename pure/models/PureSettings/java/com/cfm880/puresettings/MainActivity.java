package com.cfm880.puresettings;

import android.os.Bundle;
import android.os.RemoteException;
import android.os.ServiceManager;
// import android.pure.IHelloService;
import android.util.Log;
import android.view.View;

import android.app.Activity;

public class MainActivity extends Activity {
    private final static String TAG = "PureSettings";
    // private IHelloService service = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // service = IHelloService.Stub.asInterface(ServiceManager.getService("HelloService"));
        findViewById(R.id.btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                test();
            }
        });
    }

    private void test() {
        Log.d(TAG, "test");
        // try {
        //     // service.hello("qiushao");
        // } catch (RemoteException e) {
        //     e.printStackTrace();
        // }
    }

}
