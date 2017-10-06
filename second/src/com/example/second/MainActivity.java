package com.example.second;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Button but=(Button)findViewById(R.id.myButton);
		but.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				EditText text1=(EditText)findViewById(R.id.editText1);
				EditText text2=(EditText)findViewById(R.id.editText2);
				EditText text3=(EditText)findViewById(R.id.editText3);
				Toast toast;
				if (text1.getText().toString().equals("") || text2.getText().toString().equals("") || text3.getText().toString().equals("")) 
					toast = Toast.makeText(getApplicationContext(), "Error!", Toast.LENGTH_SHORT);
				else 
					toast = Toast.makeText(getApplicationContext(), text1.getText().toString()+
							"\n"+text2.getText().toString()+"\n"+
							text3.getText().toString(), Toast.LENGTH_SHORT);
				toast.setGravity(0, 0, 150);
			    toast.show();
			}
		});

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}