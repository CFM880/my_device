package com.cfm880.puresettings;

import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import com.pure.api.HelloManager;
import android.pure.ICallback;

import android.app.Activity;

public class MainActivity extends Activity {
    private final static String TAG = "PureSettings";
    private ICallback callback = new ICallback.Stub() {

        @Override
        public void onMessage(String message) throws RemoteException {
            Log.d(TAG, "onMessage:" + message);
        }
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                test();
            }
        });
        HelloManager.getInstance();
    }

    @Override
    protected void onResume() {
        super.onResume();
        HelloManager.getInstance().registerCallback(android.os.Process.myPid(), callback);
    }

    @Override
    protected void onStop() {
        super.onStop();
        HelloManager.getInstance().unregisterCallback(android.os.Process.myPid());
    }

    private void test() {
        Log.d(TAG, "test");
        HelloManager.getInstance().sayHello("test");
    }

}
