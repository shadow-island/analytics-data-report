using System;
using System.IO;
using System.Text;
using System.Timers;

/* 본 App 동작설명
    최초는 commit없음: 내가 커밋하고싶어서 일부로 고치지 않는이상 안일어나야한다
        (사용자에게 선택권을 줘야함)
        commit 강제로하려면 log숫자 초기화~
    2nd round는 무조건 커밋 
#기능 #UI
Todo:
    1 암것도안함 (이것도테스트필요)
    2 숫자증가만: release note   => 코드 정리
    3 기능향상:                         
        *. cls, gc새시작할대하기, -> 제자리 출력? -> 한번더 멈춘현상발생시)         
        *. commit이름 바꾸기: 종료시 EMAIL?  -> later하루에 1-2개씩 commit일때만 email? 
        *. home위치확인:exe update표시, 일단 file식으로 쉽게 -> ip추가?        
        d. 숫자증가만? file이용 = RANDOM_MAX 조정? 
        a. 강제시작 옵션만들기 <- file지울때?, 일단 이렇게했는데, 0이라 commit안되는경우있으면 이제는 날짜로하자~!        
    4 git 정리 + 1/1할차례? 
        git rebase HEAD~15 -i //하기전에 숫자바꾸고 저장함?
        git push --force(이것도됨)
        git push origin master --force(필요)
        회사컴에서는 git reset HEAD~1 --hard로 후퇴한후 다시 git pull한다
        또는 gitk에서 hard로
        또는 rebase하는 명령어찾기
    5 다른 application?(미리내 지리-> 엑셀 -> javascript?->정치or투자)
    
Release note    
    2021.       다음 시간 표시, Random 종료 기능
    2020.5.12   C#화함
    2020.2.12   python버전 시작
*/
namespace gitA
{
    class Program
    {
        // 읽어올 text file 의 경로를 지정 합니다
        static readonly string fileGit = "eukm.log";
        static readonly int WORK = 361;
        static readonly int roundMax = 21;
        static int          randomStopMax = 9;
        static int          tick;
        static int          RANDOM_MAX = 5 * 60 + 18;        
        static readonly bool debuggingMode = true;  //real mode true false    

        // global
        static int round = 1;
        // timer 2개 
        static readonly Timer timerTick = new System.Timers.Timer();
        static System.Threading.Timer myTimer = null;          

        static void Main()
        {
            if (debuggingMode)
            {
                tick = 17; //초에 한번씩 찍기
            }
            else
            {
                randomStopMax = 1;
                tick = 1; //초에 한번씩 찍기
                RANDOM_MAX = 1;// for test        
            } //debugging mode    

            Console.WriteLine("작업분ver{0}", WORK);
            var info = new FileInfo(fileGit);
            if (info.LastWriteTime.Day != DateTime.Now.Day)
            {
                Console.WriteLine("하루지나!");
                Update();
            }
            RunGit();
            
            Console.WriteLine("Press Enter to exit");

            timerTick.Interval = 1000 * tick; // 단위 milisec라서
            timerTick.Elapsed += new ElapsedEventHandler(Timer_Tick);            
            timerTick.Start();
            Timer_Tick(null, null);

            Console.ReadLine();
        }

        static void RunGit()
        {
            Console.WriteLine("Round {0} try--------------------------------", round);
            // Junbi
            Random r = new Random();
            int randomResult = r.Next(1, RANDOM_MAX + 1);
            DateTime now = DateTime.Now;
            string sTime = now.ToString("HH:mm:ss");
            DateTime target = now.AddMinutes(randomResult);
            string sTarget = target.ToString("HH:mm:ss");
            int randomStop = r.Next(1, randomStopMax + 1);

            //string sGoStop = "";
            if (round != 1 && randomStop == 1)
            {
                sTarget = "RandomStop!!!!";
            }            

            RunCommand("git pull");
            RunCommand("git status");
            RunCommand("git commit --all -m CSha_v2_r" + 
                Convert.ToString(round) + "_" + sTime + "~" + sTarget);
            
            RunCommand("git push");
            
            Console.WriteLine("randomStop={0}/{1}", randomStop, randomStopMax);
            Console.WriteLine("현재시간={0}", sTime);

            if (round != 1 && randomStop == 1)
            {
                Console.WriteLine("사고방지용 Random 종료");
                Environment.Exit(0);
            }

            if (round >= roundMax)
            {
                Console.WriteLine("사고방지용 Max 종료");
                Environment.Exit(0);
            }

            // run next round
            Console.WriteLine("현재시간={3} => {0}/{1} => {2}", randomResult, RANDOM_MAX, target, sTime);
            Console.WriteLine("in Round {0}--------------------------------", round);

            // 알람 타이머 생성 및 시작
            myTimer = new System.Threading.Timer(Timer_Elapsed, null, 1000 * randomResult * 60, 60 * 1000 * 3);
            //logic
            round++;
        }

        // 작업쓰레드가 지정된 시간 간격으로 아래 이벤트 핸들러 실행
        static void Timer_Tick(object sender, ElapsedEventArgs e)
        {
            Console.Write(DateTime.Now.ToString("HH:mm:ss "));
        }

        private static void Timer_Elapsed(object state)
        {
            if (myTimer != null)
                myTimer.Dispose();
            timerTick.Stop();
            Update();
            RunGit();
            timerTick.Start();
        }

        static void Update()
        {            
            FileInfo fi = new FileInfo(fileGit);
            //FileInfo.Exists로 파일 존재유무 확인 "
            int iNum = 0;
            string textNum;
            if (fi.Exists)
            {   //"파일존재"
                // text file 의 전체 text 를 읽어 옵니다.
                textNum = System.IO.File.ReadAllText(fileGit);
                bool isTest = int.TryParse(textNum, out iNum);
                iNum++;
            }
            else { // "파일부재" 
                //그대로 0
                Console.WriteLine("\n파일부재");
            }
            
            // Text 파일 생성 및 text 를 입력 합니다.
            textNum = Convert.ToString(iNum);
            System.IO.File.WriteAllText(fileGit, textNum, Encoding.Default);
            Console.WriteLine("\nUpdating git file value================={0}", textNum);
        }

        static void RunCommand(string command)
        {
            System.Diagnostics.ProcessStartInfo proInfo = new System.Diagnostics.ProcessStartInfo();
            System.Diagnostics.Process pro = new System.Diagnostics.Process();
            // 실행할 파일명 입력 -- cmd
            proInfo.FileName = @"cmd";
            // cmd 창 띄우기 -- true(띄우지 않기.) false(띄우기)
            proInfo.CreateNoWindow = true;
            proInfo.UseShellExecute = false;
            // cmd 데이터 받기
            proInfo.RedirectStandardOutput = true;
            // cmd 데이터 보내기
            proInfo.RedirectStandardInput = true;
            // cmd 오류내용 받기
            proInfo.RedirectStandardError = true;
            pro.StartInfo = proInfo;
            pro.Start();
            // CMD 에 보낼 명령어를 입력 합니다.
            pro.StandardInput.Write(command + Environment.NewLine);
            pro.StandardInput.Close();
            // 결과 값을 리턴 받습니다.
            string resultValue = pro.StandardOutput.ReadToEnd();
            pro.WaitForExit();
            pro.Close();
            // 결과 값을 확인 합니다.
            Console.WriteLine(resultValue);
        }
    }
}