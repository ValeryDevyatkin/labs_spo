package com.example.fifth;

import java.io.IOException;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
//CTRL+SHIFT+O

public class MainActivity extends Activity {

		static final int GALLERY_REQUEST = 1;

		@Override
		protected void onCreate(Bundle savedInstanceState) {
		    super.onCreate(savedInstanceState);
		    setContentView(R.layout.activity_main);
		    
		    Button button = (Button)findViewById(R.id.button);
		    button.setOnClickListener(new View.OnClickListener() {
		        @Override
		        public void onClick(View v) {
		        	Intent photoPickerIntent = new Intent(Intent.ACTION_PICK);
		            photoPickerIntent.setType("image/*");
		            startActivityForResult(photoPickerIntent, GALLERY_REQUEST);
		        }
		    });
		}

		@Override
		protected void onActivityResult(int requestCode, int resultCode, Intent imageReturnedIntent) {
		    super.onActivityResult(requestCode, resultCode, imageReturnedIntent);
		    Bitmap bitmap = null;
		    ImageView icon = (ImageView) findViewById(R.id.icon);
		    switch(requestCode) {
	        case GALLERY_REQUEST:
	            if(resultCode == RESULT_OK){
	                Uri selectedImage = imageReturnedIntent.getData();
	                try {
	                    bitmap = MediaStore.Images.Media.getBitmap(getContentResolver(), selectedImage);
	                } catch (IOException e) {
	                    e.printStackTrace();
	                }
	                icon.setImageBitmap(bitmap);
	            }
	    }
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}