package com.example.second;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.*;
import android.graphics.Color;

public class MainActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main); 
		final Toast toast = Toast.makeText(getApplicationContext(), "Hello, world!", Toast.LENGTH_SHORT);
	    toast.setGravity(0, 0, 200);
		final TextView tx=(TextView)findViewById(R.id.textView);
		Button button=(Button)findViewById(R.id.myButton);
		button.setOnClickListener(new View.OnClickListener() {
			int idx=0;
			@Override
			public void onClick(View arg0) {
				if (idx==0) tx.setTextColor(Color.RED);
				else if (idx==1) tx.setTextColor(Color.BLUE);
				else if (idx==2) tx.setTextColor(Color.GREEN);
				idx=(idx+1)%3;
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