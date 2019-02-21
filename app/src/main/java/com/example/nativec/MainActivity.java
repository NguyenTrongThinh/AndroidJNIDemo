package com.example.nativec;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("basiccomplex");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Number number1 = new Number(3, 3);
        Number number2 = new Number(5, 2);
        Number number3 = Add(number1, number2);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(number3.getReal() + "+" + number3.getImage() + "i");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native Number Add(Number no1, Number no2);
}
