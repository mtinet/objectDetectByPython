# objectDetectByPython

파이썬과 openCV를 이용하여 객체를 트랙킹하는 솔루션  
## Python  
- objectTracking.py  
사용법  
1. 버튼 사용법  
  - s : 화면이 멈추고 원하는 부분을 마우스로 드래그 함  
  - space : 객체 선택이 완료된 후 영상을 다시 재생함  
  - q : 프로그램을 빠져나감  

2. 실시간 카메라 사용  
$ python objectTracking.py  

3. 같은 폴더 내에 있는 동영상 파일 재생, 트래킹 수준 옵션 선택 방법  
$ python objectTracking.py --video test.mp4 --tracker mosse 

  - -v, --video : 함께 가지고 있는 영상을 통한 트랙킹 시 영상 파일을 불러오겠다는 옵션
  - -t, --tracker : 트래킹 수준을 선택하는 옵션, csrt는 FPS는 느리지만, 최고수준의 트래킹을 함, kcf는 보통 수준의 FPS와 낮은 수준의 트래킹을 함, mosse는 최고 속도를 내야할 때 사용하지만 트래킹 수준은 매우 낮음  

4. 라이브러리는 cv2, imutils가 설치되어 있어야 함  
  - AttributeError: module 'cv2.cv2' has no attribute 'TrackerCSRT_create' 오류가 날 때는 아래 명령어를 실행하여 추가 모듈을 설치함  
  - pip install opencv-contrib-python  

5. 14, 15번 줄의 시리얼 포트는 자기 컴퓨터의 OS환경에 맞춰서 수정해야함  

원 자료 출처 링크 : [클릭](https://www.pyimagesearch.com/2018/07/30/opencv-object-tracking/)

## Arduino
 - steeringControl.ino  
 사용법  
 1. 회로연결  
  - 리미트 스위치(4번, 5번) : 스티어링 휠이 한 쪽 끝에 닿았을 때 이를 인식하여 반대로 회전시켜줌  
  - 소프트웨어 시리얼 모니터링(2번, 3번) : 통신 중 시리얼로 들어오는 값을 확인하기 위해 다른 아두이노에 연결할 때 사용, 일반적인 경우에는 쓸 필요 없으며, byte로 전송되므로 입력된 값에 의해 조정된 값이 음수일 경우 소프트웨어시리얼로 모니터링 할 때는 다른 값이 표시됨  
  - 모터 제어 핀(9번, 10번) : 모터 드라이버를 제어하기 위한 신호가 송출되는 핀, 모터 드라이버의 사용법에 따르나 여기서는 아두이노용 l298n을 기준으로 사용함  
  - 모터 드라이버와 아두이노의 연결은 해당 모터드라이버의 사용법에 따름  
  
 
