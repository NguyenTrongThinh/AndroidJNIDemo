package com.example.nativec;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("complex");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Complex complex1 = new Complex(3, 3);
        Complex complex2 = new Complex(5, 2);
        Complex complex3 = Add(complex1, complex2);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(complex3.getReal() + "+" + complex3.getImage() + "i");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native Complex Add(Complex no1, Complex no2);
}
