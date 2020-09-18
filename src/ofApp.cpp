#include "ofApp.h"
using namespace ofxCv;
using namespace std;
using namespace cv;

//--------------------------------------------------------------
// Right side input fuction for Poisson Equation
// Two different exponantial function
double rho(double x, double y){
    double z = exp(-50*(x-32)*(x-32)-50*(y-32)*(y-32)) -
        exp(-30*(x-48)*(x-48)-30*(y-40)*(y-40));
    return z;
}

//--------------------------------------------------------------
void ofApp::setup()
{
    // Use only 1 double number for each Mat point:
    data = Mat::zeros( 64, 64, CV_64F ) ;
    data2 = Mat::zeros( 64, 64, CV_64F ) ;
    // Initial Boundary condition -----------
    for( int i = 0 ; i < 64 ; i++ ){
        data.at<double>( 0, i ) = 1.0;
        data.at<double>( i, 0 ) = 1.0;
        data2.at<double>( 0, i ) = 1.0;
        data2.at<double>( i, 0 ) = 1.0;
    }
    data = data * 255;
    // Convert double values to integer values to make the Mat
    // convertible to ofImage
    data.convertTo( data, CV_8U );
    toOf(data, aa);
    aa.update() ;

    // numerical analysis parameters -----
    goal = 3.9 ;
    error = 999.0 ;

    double temp_error ;
    // iteration difference equation for Laplace equation solve
    // this loop has no prolem in mathmatical logics
    t=0;
    while( error > goal ){
        error = 0.0 ;
        for( int i = 1 ; i < 63 ; i++ ){
            for( int j = 1 ; j < 63 ; j++ ){
                temp_error = data2.at< double >( i, j ) ;
                data2.at< double >( i, j ) =(
                            -rho(i, j) +
                            data2.at< double >( i - 1, j ) +
                            data2.at< double >( i + 1, j ) +
                            data2.at< double >( i, j + 1 ) +
                            data2.at< double >( i, j - 1 )
                        ) / 4.0 ;
                error += abs( temp_error - data2.at< double >( i, j ) ) ;
            }//for
        }//for
        t +=1;
    }// while
    // Convert point values from [0..1] range to [0..255] range
    data2 = data2 * 255;
    // Convert double values to integer values to make the Mat
    // convertible to ofImage
    data2.convertTo( data2, CV_8U );
    toOf(data2, bb);
    bb.update() ;
    ofLog() << "Iter= " << t;
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 200, 120);
    aa.draw(0, 0, 512, 512);
    bb.draw(513, 0, 512, 512);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
