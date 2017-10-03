package com.example.fourth;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.*;
import android.animation.*;

public class MainActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main); 

		final Button button=(Button)findViewById(R.id.myButton);
		final SeekBar bar=(SeekBar)findViewById(R.id.seekBar);
		final TextView obj1=(TextView)findViewById(R.id.obj1);
		final TextView obj2=(TextView)findViewById(R.id.obj2);
		final RadioButton radio0=(RadioButton)findViewById(R.id.radio0);
		final RadioButton radio1=(RadioButton)findViewById(R.id.radio1);
		final RadioButton radio2=(RadioButton)findViewById(R.id.radio2);
		final RadioButton radio3=(RadioButton)findViewById(R.id.radio3);
	
		button.setOnClickListener(new View.OnClickListener() {
			int duration;
			ObjectAnimator animation1=ObjectAnimator.ofFloat(obj1, "rotation", 0, 360);
			ObjectAnimator animation2=ObjectAnimator.ofFloat(obj2, "rotation", 0, 360);
			@Override
			public void onClick(View arg0) {
				duration=1000*bar.getProgress();
				
				if (radio0.isChecked()) {
					animation1.setDuration(duration);
					animation1.start();
				}
				else if (radio1.isChecked()) {
					animation2.setDuration(duration);
					animation2.start();
				}
				else if (radio2.isChecked()) {
					animation1.setDuration(duration);
					animation2.setDuration(duration);
					AnimatorSet set=new AnimatorSet();
					set.playTogether(animation1, animation2);
					set.start();
				}
				else if (radio3.isChecked()) {
					animation1.setDuration(duration);
					animation2.setDuration(duration);
					AnimatorSet set=new AnimatorSet();
					set.playSequentially(animation1, animation2);
					set.start();
				}
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