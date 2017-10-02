package com.example.seventh;

import android.app.Activity;
//import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.TextView;

public class DroidActivity2 extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main); 
		String msg="";
		TextView text=(TextView)findViewById(R.id.textView);
		if (askPermission(Manifest.permission.Camera)==0) msg=msg+"\"Camera\" granted.\n";
		if (askPermission(Manifest.permission.BATTERY_STATE)==0) msg=msg+"\"BATTERY_STATE\" granted.\n";
		if (askPermission(Manifest.permission.READ_CONTACTS)==0) msg=msg+"\"READ_CONTACTS\" granted.\n";
		if (askPermission(Manifest.permission.WRITE_CONTACTS)==0) msg=msg+"\"WRITE_CONTACTS\" granted.\n";
		if (askPermission(Manifest.permission.WIFI_STATE)==0) msg=msg+"\"WIFI_STATE\" granted.\n";
		text.setText(msg);
	}

	private int askPermission(String camera) {
		// TODO Auto-generated method stub
		return 0;
	}
}