//
//  Object.h
//  patternExample
//
//  Created by 神田竜 on 2013/08/05.
//
//

#ifndef patternExample_Object_h
#define patternExample_Object_h

class slide : public ofPoint{
private:

    ofPoint p;
    
    float speed;
    
public:
    
    slide():speed(0.1){
    }
    
    void set(float _px,float _py,float _pz){
        p.x = _px;
        p.y = _py;
        p.z = _pz;
    }
    
    void set(float _px,float _py){
        p.x = _px;
        p.y = _py;
    }
    
    void imSet(float _px,float _py,float _pz){
        p.x = _px;
        p.y = _py;
        p.z = _pz;
        
        x = _px;
        y = _py;
        z = _pz;
    }
    
    void imSet(float _px,float _py){
        p.x = _px;
        p.y = _py;
        
        x = _px;
        y = _py;

    }
    
    void update(){
        x += (p.x - x) * speed;
        y += (p.y - y) * speed;
        z += (p.z - z) * speed;
    }
};


class Primitive{
public:
    
    ofPoint pos;
    slide size;
    slide rotate;
    ofColor color;
    int drawMode;
    bool bFill;
    float audioVal;
    int rotAxisMode;
    
    Primitive():bFill(false),rotAxisMode(1){
        color.set(255,255,255,255);
        size.set(10,10);
        drawMode = 0;
        pos.set(ofGetWidth() * 0.5 ,ofGetHeight() * 0.5);
    }
    void update(){
        //size.set(audioVal*200.0,audioVal*200.0);
    }
        
    void draw(){
        ofPushMatrix();
        ofPushStyle();
        ofSetRectMode(OF_RECTMODE_CENTER);
        if(bFill)ofFill();
        else ofNoFill();
        
        ofSetColor(color.r,color.g,color.b,color.a);
        
        if(rotAxisMode == 1)ofTranslate(pos.x,pos.y,pos.z);
        else if(rotAxisMode == 0)ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
        
        ofRotateX(rotate.x);
        ofRotateY(rotate.y);
        ofRotateZ(rotate.z);
        
        if(rotAxisMode == 0){
            ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
            ofTranslate(pos.x,pos.y,pos.z);
        }
        if(drawMode == 0) ofDrawBox(0,0,0,size.x,size.y,size.z);
        else ofDrawSphere(0,0,0,size.x * 0.5);
        ofPopStyle();
        ofPopMatrix();
        
    }
};

#endif
