package com.example.third;

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
		
		final ImageView back = (ImageView) findViewById(R.id.background);
		final Toast toast = Toast.makeText(getApplicationContext(), "Image", Toast.LENGTH_SHORT);
		toast.setGravity(0, 0, 200);
		
		Button button1=(Button)findViewById(R.id.blackButton);
		button1.setBackgroundColor(Color.GRAY);
		button1.setOnClickListener(new View.OnClickListener() {	
			@Override
			public void onClick(View arg0) {
			    back.setBackgroundColor(Color.BLACK);
			    toast.setText("Black");
			    toast.show();
			}
		});
		
		Button button2=(Button)findViewById(R.id.whiteButton);
		button2.setBackgroundColor(Color.GRAY);
		button2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
			    back.setBackgroundColor(Color.WHITE);
			    toast.setText("White");
			    toast.show();
			}
		});
		
		Button button3=(Button)findViewById(R.id.greenButton);
		button3.setBackgroundColor(Color.GRAY);
		button3.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
			    back.setBackgroundColor(Color.GREEN);
			    toast.setText("Green");
			    toast.show();
			}
		});
		
		Button button4=(Button)findViewById(R.id.imageButton);
		button4.setBackgroundColor(Color.GRAY);
		button4.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				back.setBackgroundResource(R.drawable.matrix);		
				toast.setText("Image");
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