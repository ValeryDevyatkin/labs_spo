package com.example.sixth;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.example.sixth.FileOperations;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		final Button readButton=(Button)findViewById(R.id.readButton);
		final Button writeButton=(Button)findViewById(R.id.writeButton);
		final EditText text1=(EditText)findViewById(R.id.editText1);
		final EditText text2=(EditText)findViewById(R.id.editText2);
		final EditText text3=(EditText)findViewById(R.id.editText3);
		final EditText fname=(EditText)findViewById(R.id.fname);
		final EditText fnameread=(EditText)findViewById(R.id.fnameread);

		
	    writeButton.setOnClickListener(new View.OnClickListener() {
	        @Override
	        public void onClick(View arg0) {
	            // TODO Auto-generated method stub
		        String filename = fname.getText().toString();
		        FileOperations fop = new FileOperations();
				if (!text1.getText().toString().equals("") && !text2.getText().toString().equals("") && !text3.getText().toString().equals("")) {
					String content=text1.getText().toString()+"\n"+text2.getText().toString()+"\n"+text3.getText().toString();
					fop.write(filename, content);
			        if (fop.write(filename, content)) {
			        	Toast.makeText(getApplicationContext(), "XXX"+filename+".txt created", Toast.LENGTH_SHORT).show();
			        	fnameread.setText(filename);
			        } else {
			            Toast.makeText(getApplicationContext(), "I/O error", Toast.LENGTH_SHORT).show();
			        }
				}
	        }
	    });
	                
	    readButton.setOnClickListener(new View.OnClickListener() {
	        @Override
	        public void onClick(View arg0) {
		        // TODO Auto-generated method stub
		        String readfilename = fnameread.getText().toString();
		        FileOperations fop = new FileOperations();
		        String text = fop.read(readfilename);
		        if(text != null) Toast.makeText(getApplicationContext(), text, Toast.LENGTH_SHORT).show();
	        else 
	            Toast.makeText(getApplicationContext(), "File not Found", Toast.LENGTH_SHORT).show();
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