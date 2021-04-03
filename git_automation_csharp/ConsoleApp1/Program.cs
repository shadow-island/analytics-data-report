using System;
using System.IO;
using System.Text;
using System.Timers;
/* 본 App 동작설명
    최초는 commit없음: 내가 커밋하고싶어서 일부로 고치지 않는이상 안일어나야한다
    (사용자에게 선택권을 줘야함)
    2nd round는 무조건 커밋 
#기능 #UI
Todo:
    1.암것도안함 (이것도테스트필요)
    2 숫자증가만: release note => 코드 정리
    3 기능향상: 
        random 종료 기능 필요할듯?
        RANDOM_MAX를 version에 보이기(아니 지금도 보이는것같고)
        random number 보이기-> 다음 시간으로 표시
        file이용 = RANDOM_MAX 조정? 
        commit이름 바꾸기->  EMAIL?, (제자리 출력? -> 한번더 멈춘현상발생시)
    4 git 정리 + 밑에할차례?
        git rebase HEAD~13 -i //하기전에 숫자바꾸고 저장함?
        git push --force
        git push origin master --force(필요)
        회사컴에서는 git reset HEAD~1 --hard로 후퇴한후 다시 git pull한다
    5 다른 application?(미리내javascript?->정치)
    
Release note    
    2020.5.12 C#화함
    2020.2.12 python버전 시작
*/
namespace gitA
{
    class Program
    {        
        static readonly int roundMax    = 21;
        static readonly int work        = 352;
        //static readonly int tick        = 14; //초에 한번씩 찍기
        static readonly int tick = 1; //초에 한번씩 찍기
        //static readonly int RANDOM_MAX  = 5 * 60 + 9;//real mode
        static readonly int RANDOM_MAX = 1;// for test

        // 읽어올 text file 의 경로를 지정 합니다
        static readonly string fileGit = "eukm.log";
        static int round = 1;
        static readonly Timer timerTick = new System.Timers.Timer();
        static System.Threading.Timer myTimer = null;

        static void Main()
        {
            Console.WriteLine("작업분ver{0}", work);
            var info = new FileInfo(fileGit);
            if (info.LastWriteTime.Day != DateTime.Now.Day)
            {
                Console.WriteLine("하루지나!");
                Update();
            }
            RunGit();
            
            timerTick.Interval = 1000 * tick; // 단위 milisec라서
            timerTick.Elapsed += new ElapsedEventHandler(Timer_Tick);
            timerTick.Start();

            Console.WriteLine("Press Enter to exit");
            Console.ReadLine();
        }

        static void RunGit()
        {
            Random r = new Random();
            int randomResult = r.Next(1, RANDOM_MAX + 1);
            //int randomResult = r.Next(1, 3 + 1);

            string sTime = DateTime.Now.ToString("_HH:mm:ss_");

            Console.WriteLine("Round {0}--------------------------------", round);
            RunCommand("git pull");
            RunCommand("git status");
            RunCommand("git commit --all -m CSha_v2_r" + 
                Convert.ToString(round) + sTime + Convert.ToString(randomResult));
            RunCommand("git push");

            int randomStopMax = 3;
            int randomStop = r.Next(1, randomStopMax + 1);

            Console.WriteLine("randomStop={0}/{1}", randomStop, randomStopMax);
            if (randomStop == 1)
            {                
                Environment.Exit(0);
            }


            if (round >= roundMax)
            {
                Console.WriteLine("사고방지용 안전히 종료");
                Environment.Exit(0);
            }


            // 알람 타이머 생성 및 시작

            myTimer = new System.Threading.Timer(Timer_Elapsed, null, 1000 * randomResult * 60, 60 * 1000 * 3);

            DateTime now = DateTime.Now;
            sTime = now.ToString("HH:mm:ss");

            DateTime target = now.AddMinutes(randomResult);
            Console.WriteLine("현재시간={3} ~{0}/{1},{0}분후=>{2}", randomResult, RANDOM_MAX, target, sTime);
            Console.WriteLine("Round {0}--------------------------------", round);
            round++;
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
            // text file 의 전체 text 를 읽어 옵니다.
            string textValue = System.IO.File.ReadAllText(fileGit);
            int numVal = 0;
            bool isTest = int.TryParse(textValue, out numVal);
            numVal++;
            // Text 파일 생성 및 text 를 입력 합니다.
            textValue = Convert.ToString(numVal);
            System.IO.File.WriteAllText(fileGit, textValue, Encoding.Default);
            Console.WriteLine("\nUpdating git file================={0}", textValue);
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


        // 작업쓰레드가 지정된 시간 간격으로 아래 이벤트 핸들러 실행
        static void Timer_Tick(object sender, ElapsedEventArgs e)
        {
            Console.Write(DateTime.Now.ToString("HH:mm:ss "));
        }
    }
}
