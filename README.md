# objectDetectByPython

파이썬과 openCV를 이용하여 객체를 트랙킹하는 솔루션  

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


원 자료 출처 링크 : [클릭](https://www.pyimagesearch.com/2018/07/30/opencv-object-tracking/)
