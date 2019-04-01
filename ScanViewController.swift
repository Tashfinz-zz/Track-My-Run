//
//  ScanViewController.swift
//  LFopen2Demo
//
//  Created by Dulip Gayan Dasanayaka on 3/10/16.
//  Copyright © 2016 Lifefitness. All rights reserved.
//

import UIKit
import AVFoundation

protocol QRDelegate {
    func barcodeReaded(_ barcode: String)
}

class ScanViewController: UIViewController , AVCaptureMetadataOutputObjectsDelegate{

    @IBOutlet weak var cancelBtn:UIButton?
    var delegate: QRDelegate?
    var captureSession: AVCaptureSession!
    var code: String?

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func onTapCancelButton(){
        self.dismiss(animated: true, completion: nil);
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.captureSession = AVCaptureSession();
        
        let videoCaptureDevice: AVCaptureDevice = AVCaptureDevice.defaultDevice(withMediaType: AVMediaTypeVideo)
        
        do {
            
            let videoInput = try AVCaptureDeviceInput(device: videoCaptureDevice)
            
            if self.captureSession.canAddInput(videoInput) {
                self.captureSession.addInput(videoInput)
            } else {
                print("Could not add video input")
            }
            
            let metadataOutput = AVCaptureMetadataOutput()
            if self.captureSession.canAddOutput(metadataOutput) {
                self.captureSession.addOutput(metadataOutput)
                
                metadataOutput.setMetadataObjectsDelegate(self, queue: DispatchQueue.main)
                metadataOutput.metadataObjectTypes = [AVMetadataObjectTypeQRCode, AVMetadataObjectTypeEAN13Code]
            } else {
                print("Could not add metadata output")
            }
            
            let previewLayer = AVCaptureVideoPreviewLayer(session: self.captureSession)
            previewLayer?.frame = self.view.bounds;//CGRect(x: self.view.bounds.origin.x, y: 50, width: self.view.bounds.size.width, height: 300)
            self.view.layer .addSublayer(previewLayer!)
            self.captureSession.startRunning()
        } catch let error as NSError {
            print("Error while creating vide input device: \(error.localizedDescription)")
        }
     
        self.view.bringSubview(toFront: self.cancelBtn!)
    }
    
    func captureOutput(_ captureOutput: AVCaptureOutput!, didOutputMetadataObjects metadataObjects: [Any]!, from connection: AVCaptureConnection!) {
        for metadata in metadataObjects {
            let readableObject = metadata as! AVMetadataMachineReadableCodeObject
            let code = readableObject.stringValue
            if !(code?.isEmpty)! {
                self.captureSession.stopRunning()
                self.dismiss(animated: true, completion: nil)
                self.delegate?.barcodeReaded(code!)
            }
        }
    }

}
