package com.cfm880.puresettings;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import com.pure.api.HelloManager;

import android.app.Activity;

public class MainActivity extends Activity {
    private final static String TAG = "PureSettings";
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

    private void test() {
        Log.d(TAG, "test");
        HelloManager.getInstance().sayHello("test");
    }

}
