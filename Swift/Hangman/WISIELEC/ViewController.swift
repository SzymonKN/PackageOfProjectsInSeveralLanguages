//
//  ViewController.swift
//  WISIELEC
//
//  Created by Kutyba Król on 29.09.2016.
//  Copyright © 2016 Kablociag Syrek i spolka. All rights reserved.
//

import UIKit

struct strukt {
    var gr : String
    var kat : [String]
}

class ViewController: UIViewController, UIPickerViewDelegate{
    
    
    @IBOutlet weak var pv: UIPickerView!
    var pierwszakolumna : Int = 0
    var licznikGr  : Int = 0
    var licznikKat : Int = 0
    var dane = [
        strukt(gr:"Natura", kat:["Zwierzęta","Rośliny"]),
        strukt(gr:"Alkohole", kat:["Piwo","Wódka"]),
        strukt(gr:"Góry", kat:["Szczyty","Pasma"]),
     //   strukt(gr:"Grupa 4", kat:["kat 4.1","kat 4.2","kat 4.3"]),
    ]
    var pickOption = ["one", "two", "three", "seven", "fifteen","fdd"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        pv.delegate = self
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    @IBOutlet weak var graj: UIButton!
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
        let vc : UIViewController = (self.storyboard?.instantiateViewController(withIdentifier: "w2"))!
        self.show(vc, sender: vc)
        
    }
    
    func numberOfComponentsInPickerView(_ pickerView: UIPickerView) -> Int
    {
     return 2
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) ->
        Int {
        if(component == 0){
            return dane.count
        }else{
            return dane[pickerView.selectedRow(inComponent: 0)].kat.count
            }
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if(component == 0){
            return dane[row].gr
        }
        else{
            return  dane[pickerView.selectedRow(inComponent: 0)].kat[row]
        }
     //   tab[pickerView.selectedRow(inComponent: 0)]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        //if(pickerView.selectedRow(inComponent: 0) != pierwszakolumna){
        if(component==0){
        pickerView.selectRow( 0 , inComponent: 1, animated: false)
         }
        //pierwszakolumna=pickerView.selectedRow(inComponent: 0)
        //print(pickerView.selectedRow(inComponent: 0) )
        pickerView.reloadAllComponents()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let dest = segue.destination as! ViewController2
        // print(segue.identifier)
            dest.kat=dane[pv.selectedRow(inComponent: 0)].gr
            dest.podkat=dane[pv.selectedRow(inComponent: 0)].kat[pv.selectedRow(inComponent: 1)]
            
       
        
    }
}

