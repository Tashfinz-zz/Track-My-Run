//
//  ViewController.swift
//  LFopen2Demo
//
//  Created by Dulip Gayan Dasanayaka on 30/9/16.
//  Copyright © 2016 Lifefitness. All rights reserved.
//

import UIKit
import CoreBluetooth


class LFMainViewController: UIViewController,
                            QRDelegate,
                            LFWorkoutSessionDelegate ,
                            UITableViewDelegate,
                            UITableViewDataSource,
                            CBCentralManagerDelegate,
                            UITextFieldDelegate {

    let device_outofrange =                     -80
    let device_near     =                       -52
    let device_can_connect_iphone =             -48
    
    @IBOutlet weak var scanButton:UIButton?
    @IBOutlet weak var proximityButton:UIButton?
    @IBOutlet weak var workoutTable:UITableView?
    @IBOutlet weak var resetButton:UIButton?
    var connectionMgr:LFEquipmentConnectionManager?
    var qrCodetext:String?
    var stream:LFWorkoutStream?
    
    var rssi_value_map:NSMutableDictionary? = NSMutableDictionary.init()
    var centralManager:CBCentralManager?
    var selected_name: String = ""
    var messageView:UITextView?
    var timer: Timer?
    
    var timerCount: Int = 0
    
    var workoutItems: Array<WorkoutItem> = []
    

    override func viewDidLoad() {
        super.viewDidLoad()
        connectionMgr = LFEquipmentConnectionManager.shared();
        connectionMgr?.register(forWorkoutSession: self, sessionType: LFRealWorkoutSession)
        connectionMgr?.userInfoDataSource = self
        
        //initiate central manager
        centralManager = CBCentralManager.init(delegate: self, queue: DispatchQueue.global())
        self.timer = Timer.scheduledTimer(timeInterval: 5, target: self, selector: #selector(onExpireScanTimer), userInfo: nil, repeats: true)
        self.proximityButton?.isHidden = true
        
        messageView = UITextView.init(frame: CGRect(x: 0, y: 0, width: self.view.frame.size.width, height: 200))
        self.view.bringSubview(toFront: self.resetButton!)
        self.resetButton?.isHidden = true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func onTapScanButton(){
        self.performSegue(withIdentifier: "show_scan_view", sender: self)
    }
    
    @IBAction func onTapProximitButton(){
        LFEquipmentConnectionManager.shared().connectThroughBluetooth(usingEquipmentName: self.selected_name)
        self.timer?.invalidate()
        self.rssi_value_map?.removeAllObjects()
        self.centralManager?.stopScan()
        self.timer = nil;
        self.centralManager = nil;
    }
    
    /* LFWorkoutSessionDelegate */
    func didDeviceDisconnect() {
        print(" device disconnected ")
        let alert = UIAlertController(title: "Connect", message: "Fail to connect for LFequipment", preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        self.present(alert, animated: true) {}
        scanButton?.setBackgroundImage(UIImage.init(named: "Scan"), for: UIControlState.normal)
        self.resetButton?.isHidden = false
    }
    
    func didDeviceConnect() {
        print(" device disconnected ")
        let alert = UIAlertController(title: "Connect", message: "Successfully connected to LFequipment", preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        self.present(alert, animated: true) {}
        scanButton?.setBackgroundImage(UIImage.init(named: "connected"), for: UIControlState.normal)
        self.proximityButton?.isHidden = true
    }
    
    func didPauseWorkout() {
        print("Pause workout")
    }
    
    func didFinishedWorkout() {
        print("Finish workout")
    }
    
    func didStartWorkout() {
         print("Start workout")
    }
    
    func didReceivedEquipmentInfo(_ equipment: LFEquipment!) {
        print("Equipment type : \(equipment.eqType)")
    }
    
    func didReceivedWorkoutStream(_ streamData: LFWorkoutStream!) {
        self.stream = streamData as LFWorkoutStream?
        let item = WorkoutItem (distance: stream?.accumulatedDistance, speed: stream?.currentSpeedKM, time: Double(self.timerCount))
        self.workoutItems.append(item)
        self.workoutTable?.reloadData()
        print("stream : \(String(describing: self.stream))")
        //Edited by Tashfin Shahid
    }
    
 

    //func didWriteLogMessage(_ log: String){
     //   print ("Log : \(log)")
   // }
    
    func didReceivedResult(_ equipmentResult: LFCardioEquipmentWorkoutResult!) {
        let alert = UIAlertController(title: "Result", message: equipmentResult.workoutResultDetails, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        self.present(alert, animated: true) {}
        scanButton?.setBackgroundImage(UIImage.init(named: "Scan"), for: UIControlState.normal)

        self.messageView!.text = self.messageView!.text + equipmentResult.workoutResultDetails
        scanButton?.setBackgroundImage(UIImage.init(named: "Scan"), for: UIControlState.normal)
        self.resetButton?.isHidden = false;
    }
    
    func didFailConnection(_ error: Error!) {
        print("Error : \(error)")
    }
    
    func didFail(toProcessResultData error: Error!) {
        print("Error : \(error)")
    }
    
    func didFindBluetoothSupportEquipments(_ lfSupportEquipmentList: [Any]!) {
        
    }
    
    /* UITableViewDelegate */
    func numberOfSections(in tableView: UITableView) -> Int {
        return 3
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section == 0 {
            return 4
        }else if section == 1{
            return 4
        }else{
            return 0;
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell-identifire", for: indexPath)
        if indexPath.section == 0 && indexPath.row == 0 {
            cell.textLabel?.text = "Duration"
            if let dur = self.stream?.elapsedWorkoutSeconds as Int32? {
               cell.detailTextLabel?.text = String(dur)
            }else{
                cell.detailTextLabel?.text =  "0"
            }
        }else if indexPath.section == 0 && indexPath.row == 1 {
            cell.textLabel?.text = "Distance"
            if let dis = self.stream?.accumulatedDistance as Double? {
                cell.detailTextLabel?.text = String(format: "%.2f",dis)
            }else{
                cell.detailTextLabel?.text =  "0.00"
            }
        }else if indexPath.section == 0 && indexPath.row == 2 {
            cell.textLabel?.text = "Calorie"
            if let cal = self.stream?.accumulatedCalories as Int32? {
                cell.detailTextLabel?.text = String(format: "%d",cal)
            }else{
                cell.detailTextLabel?.text =  "0"
            }
        }else if indexPath.section == 0 && indexPath.row == 3{
            cell.textLabel?.text = "Speed"
            if let spd = self.stream?.currentSpeedKM as Double? {
                cell.detailTextLabel?.text =  String(format: "%.2f",spd)
            }else{
                cell.detailTextLabel?.text =  "0.00"
            }
        }else if indexPath.section == 1 && indexPath.row == 0 {
            cell.textLabel?.text = "Set Incline"
            cell.detailTextLabel?.text =  ""
        }else if indexPath.section == 1 && indexPath.row == 1 {
            cell.textLabel?.text = "Set Level"
            cell.detailTextLabel?.text =  ""
        }else if indexPath.section == 1 && indexPath.row == 2{
            cell.textLabel?.text = "Set HR"
            cell.detailTextLabel?.text =  ""
        }else if indexPath.section == 1 && indexPath.row == 3{
            cell.textLabel?.text = "Set Display Text"
            cell.detailTextLabel?.text =  ""
        }
        
        return cell
    }
    
    
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        if indexPath.section == 1 {
            
            if indexPath.row == 0 {
                
                let avc = UIAlertController.init(title: "Set Incline", message: "", preferredStyle: UIAlertControllerStyle.alert)
                let action = UIAlertAction.init(title: "Cancel", style: UIAlertActionStyle.destructive, handler: { (action) in
                    self.dismiss(animated: true, completion: nil)
                });
                
                let actionOk = UIAlertAction.init(title: "Ok", style: UIAlertActionStyle.default, handler: { (action) in
                    
                    if let incline = avc.textFields?.first?.text {
                        LFEquipmentConnectionManager.shared().setIncline(Double(incline)!, responseStatus: { (status, error) in
                            NSLog("Successfully set incline value %@ \n", incline + "\n")
                            self.messageView!.text = self.messageView!.text + "Successfully set Incline value \n" + incline
                        })
                    }
                    
                    self.dismiss(animated: true, completion: nil)
                });
                
                avc.addTextField(configurationHandler: { (textFiled) in
                    textFiled.delegate = self
                    textFiled.placeholder = "Set Incline"
                    textFiled.keyboardType = UIKeyboardType.decimalPad
                })
                avc .addAction(action)
                avc.addAction(actionOk)
                
                self.present(avc, animated: true, completion: { })
                
            }else if indexPath.row == 1{
                
                let avc = UIAlertController.init(title: "Set Level", message: "", preferredStyle: UIAlertControllerStyle.alert)
                let action = UIAlertAction.init(title: "Cancel", style: UIAlertActionStyle.destructive, handler: { (action) in
                    self.dismiss(animated: true, completion: nil)
                });
                
                let actionOk = UIAlertAction.init(title: "Ok", style: UIAlertActionStyle.default, handler: { (action) in
                    
                    if let level = avc.textFields?.first?.text {
                        LFEquipmentConnectionManager.shared().setWorkoutLevel(Int32(level)!, responseStatus: { (status, error) in
                            NSLog("Successfully set incline value %@ \n", level)
                            self.messageView!.text = self.messageView!.text + "Successfully set Level value \n" + level
                        })
                    }
                    
                    self.dismiss(animated: true, completion: nil)
                });
                
                avc.addTextField(configurationHandler: { (textFiled) in
                    textFiled.delegate = self
                    textFiled.placeholder = "Set level"
                    textFiled.keyboardType = UIKeyboardType.numberPad
                })
                avc .addAction(action)
                avc.addAction(actionOk)
                
                self.present(avc, animated: true, completion: { })
                
            }else if indexPath.row == 2{
                
                let avc = UIAlertController.init(title: "Set Heart Rate", message: "", preferredStyle: UIAlertControllerStyle.alert)
                let action = UIAlertAction.init(title: "Cancel", style: UIAlertActionStyle.destructive, handler: { (action) in
                    self.dismiss(animated: true, completion: nil)
                });
                
                let actionOk = UIAlertAction.init(title: "Ok", style: UIAlertActionStyle.default, handler: { (action) in
                    
                    if let hr = avc.textFields?.first?.text {
                        LFEquipmentConnectionManager.shared().setWorkoutTargetHeartRate(Int32(hr)!, responseStatus: { (status, error) in
                            NSLog("Successfully set Heart Rate value %@ \n", hr)
                            self.messageView!.text = self.messageView!.text + "Successfully set Heart Rate value \n" + hr
                        })
                    }
                    
                    self.dismiss(animated: true, completion: nil)
                });
                
                avc.addTextField(configurationHandler: { (textFiled) in
                    textFiled.delegate = self
                    textFiled.placeholder = "Set HR"
                    textFiled.keyboardType = UIKeyboardType.numberPad
                })
                avc .addAction(action)
                avc.addAction(actionOk)
                self.present(avc, animated: true, completion: { })
                
            }else if indexPath.row == 3{
                
                let avc = UIAlertController.init(title: "Enter text to disply on Console", message: "", preferredStyle: UIAlertControllerStyle.alert)
                let action = UIAlertAction.init(title: "Cancel", style: UIAlertActionStyle.destructive, handler: { (action) in
                    self.dismiss(animated: true, completion: nil)
                });
                
                let actionOk = UIAlertAction.init(title: "Ok", style: UIAlertActionStyle.default, handler: { (action) in
                    
                    if let text = avc.textFields?.first?.text {
                        
                        LFEquipmentConnectionManager.shared().setMessageToDispalyOnEquipmentScreen(text, responseStatus: { (status, error) in
                            NSLog("Successfully set text value %@ \n", text)
                            self.messageView!.text = self.messageView!.text + "Successfully set text value \n\n "
                            if let err = error{
                                self.messageView!.text = self.messageView!.text + err.localizedDescription
                            }
                        })
                    }
                    
                    self.dismiss(animated: true, completion: nil)
                });
                
                avc.addTextField(configurationHandler: { (textFiled) in
                    textFiled.delegate = self
                    textFiled.placeholder = "Enter text"
                    textFiled.keyboardType = UIKeyboardType.alphabet
                })
                
                avc .addAction(action)
                avc.addAction(actionOk)
                self.present(avc, animated: true, completion: { })
                
            }

        }
}
    
    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        if section == 2 {
            return 200
        }
        
        return 0
    }
    
    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        if section == 2 {
            let view = UIView()
            view.frame = CGRect(x: 0, y: 0, width: tableView.frame.size.width, height: 200)
            if let msgView = self.messageView {
                view.addSubview(msgView)
            }
            
            return view;
        }
        
        return UIView()
    }
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if section == 0 {
            return "Current Workout Data"
        }else if section == 1{
            return "Control Workout"
        }else{
            return "Logs"
        }
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.destination.isKind(of: ScanViewController.classForCoder()) {
            let svc:ScanViewController = (segue.destination as? ScanViewController)!
            svc.delegate = self
        }
    }
    
    func barcodeReaded(_ barcode: String){
        self.qrCodetext = barcode;
        connectionMgr?.connectThroughBluetooth(usingQRvalue: self.qrCodetext, response: { (success, error) in
            print("Error %@", error ?? NSError.init())
        })
    }
    
    /* CBCentralManagerDelagte */
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        if central.state == CBManagerState.poweredOn {
            self.centralManager?.scanForPeripherals(withServices: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey:true])
        }
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {

        let isLfEquipment =  LFEquipmentConnectionManager.shared().isLifefitnessEquipment(advertisementData)
        if isLfEquipment {
            if let device_name = advertisementData["kCBAdvDataLocalName"] {
                NSLog(device_name as! String)
                var rssi_list = self.rssi_value_map!.object(forKey: device_name) as! NSMutableArray?
                if rssi_list == nil {
                    rssi_list = NSMutableArray.init()
                    self.rssi_value_map!.setObject(rssi_list ?? NSMutableArray.init(), forKey: device_name as! NSCopying)
                }
                
                if RSSI.doubleValue < 0 {
                    print(RSSI)
                    if let list = rssi_list {
                        list.add(RSSI)
                    }
                }
            }
        }
    }
    
    func onExpireScanTimer(sender:Any?){
        self.centralManager?.stopScan()
        
        var best_rssi_index: Int = -1
        var best_average_rssi_value: Int = -120
        var index  = 0
        let keys:[String] = self.rssi_value_map!.allKeys as! [String]
        
        for  device_name in keys {
            
            let list: NSArray? = self.rssi_value_map!.object(forKey: device_name) as? NSArray
            var total = 0
            for rssi_val  in list as! [Int] {
                total = total + rssi_val
            }
            
            var avg = 0
            if let val_list = list {
                if val_list.count > 0 {
                    avg = total/val_list.count
                }
            }

            if avg > best_average_rssi_value {
                best_average_rssi_value = avg
                best_rssi_index = index
            }
            
            index += 1;
        }
        
        if keys.count>0 && keys.count >= (best_rssi_index+1)  {
            self.selected_name = keys[best_rssi_index]
        }
        
        print(best_average_rssi_value)
        handleProximmityButton(nearestRssivalue: best_average_rssi_value)

        if best_average_rssi_value > 0 {
            self.rssi_value_map?.removeAllObjects()
            self.centralManager?.scanForPeripherals(withServices: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey: true])
        }
        
        self.rssi_value_map?.removeAllObjects()
        self.centralManager?.scanForPeripherals(withServices: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey:true])
    }
    
    func handleProximmityButton(nearestRssivalue: Int) {
        let rssi =  nearestRssivalue
        
        DispatchQueue.main.async {
            if rssi < self.device_outofrange {
               self.proximityButton?.isHidden = true
               self.timerCount  = 0
            }else if rssi > self.device_can_connect_iphone {
                self.proximityButton?.isHidden = false
                self.timerCount = 0
            }else {
                self.proximityButton?.isHidden = true
            }
        }
    }
    
    @IBAction func reset() {
        self.messageView?.text = ""
        self.stream = nil
        self.workoutTable?.reloadData()
        self.workoutItems.removeAll()
        
        // start scaning
        centralManager = CBCentralManager.init(delegate: self, queue: DispatchQueue.global())
        self.timer = Timer.scheduledTimer(timeInterval: 5, target: self, selector: #selector(onExpireScanTimer), userInfo: nil, repeats: true)
        self.proximityButton?.isHidden = true
    }

}

extension LFMainViewController: LFUserInfoDataSource {
    
    func requestUserInfoXML() -> String {
        return "<?xml version=\"1.0\" encoding=\"UTF-8\"?><discover><profile><first_name>Friend</first_name><last_name> </last_name><nick_name>Friend</nick_name></profile></discover>"
    }
    
    func didRequestUserSettings() -> String {
        return " "
    }
}
