package com.example.eighth;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		final Button b=(Button)findViewById(R.id.button);
		final Button history=(Button)findViewById(R.id.history);
		final Button back=(Button)findViewById(R.id.back);
		final Button forward=(Button)findViewById(R.id.forward);
		final Button title=(Button)findViewById(R.id.title);
		final WebView wv=(WebView)findViewById(R.id.webView);
		

		wv.setWebViewClient(new MyBrowser(){
			public void onPageFinished(WebView view, String url) {
				title.setText(wv.getTitle());
				if (!wv.canGoForward()) forward.setText("!forward");
				else forward.setText("forward");
				if (!wv.canGoBack()) back.setText("!back");
				else back.setText("back");
				if (wv.canGoForward() || wv.canGoBack()) history.setText("clear history");
				else history.setText("empty");
			}	
		});
		
		b.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				String url = "https://www.google.by/?gws_rd=ssl";
				wv.getSettings().setLoadsImagesAutomatically(true);
				wv.getSettings().setJavaScriptEnabled(true);
				wv.setScrollBarStyle(View.SCROLLBARS_INSIDE_OVERLAY);
				wv.loadUrl(url);
			}
		});
		
		history.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				wv.clearHistory();
				back.setText("!back");
				forward.setText("!forward");
				history.setText("empty");
			}
		});
		
		back.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if (!wv.canGoBack()) back.setText("!back");
				else {
//					back.setText("back");
					wv.goBack();
				}
			}
		});
		
		forward.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if (!wv.canGoForward()) forward.setText("!forward");
				else {
//					forward.setText("forward");
					wv.goForward();
				}
			}
		});
	}

	private class MyBrowser extends WebViewClient {
		@Override
		public boolean shouldOverrideUrlLoading(WebView view, String url) {
			view.loadUrl(url);
			return true;
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}