<<<<<<< HEAD
package com.example.a4ib2.projektkoncowynowaks;

import android.content.Context;
import android.hardware.Camera;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.FrameLayout;

/**
 * Created by Szymon1 on 2016-10-08.
 */

public class CameraPreview   extends  SurfaceView implements SurfaceHolder.Callback{
    private Camera _camera;
    private SurfaceHolder _surfaceHolder;





    public CameraPreview(Context context, Camera _camera) {
        super(context);
        this._camera = _camera;
      //  this._camera = camera;
        this._surfaceHolder = this.getHolder();
        this._surfaceHolder.addCallback(this);
        _camera.setDisplayOrientation(90);
    }


    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {


        try {
            _camera.setPreviewDisplay(_surfaceHolder);
            _camera.startPreview();
        } catch (Exception e) {
            e.printStackTrace();
        }


    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int i1, int i2) {

        try {
            _camera.setPreviewDisplay(_surfaceHolder);
            _camera.startPreview();
        } catch (Exception e) {
            e.printStackTrace();
        }

        //try  {

        //}
        //catch {

//        }

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {

    }
}
=======
package com.example.a4ib2.projektkoncowynowaks;

import android.content.Context;
import android.hardware.Camera;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.FrameLayout;

/**
 * Created by Szymon1 on 2016-10-08.
 */

public class CameraPreview   extends  SurfaceView implements SurfaceHolder.Callback{
    private Camera _camera;
    private SurfaceHolder _surfaceHolder;





    public CameraPreview(Context context, Camera _camera) {
        super(context);
        this._camera = _camera;
      //  this._camera = camera;
        this._surfaceHolder = this.getHolder();
        this._surfaceHolder.addCallback(this);
        _camera.setDisplayOrientation(90);
    }


    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {


        try {
            _camera.setPreviewDisplay(_surfaceHolder);
            _camera.startPreview();
        } catch (Exception e) {
            e.printStackTrace();
        }


    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int i1, int i2) {

        try {
            _camera.setPreviewDisplay(_surfaceHolder);
            _camera.startPreview();
        } catch (Exception e) {
            e.printStackTrace();
        }

        //try  {

        //}
        //catch {

//        }

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {

    }
}
>>>>>>> 7780897e3c05ad584d10e9aba621b7e1cc246ea4
