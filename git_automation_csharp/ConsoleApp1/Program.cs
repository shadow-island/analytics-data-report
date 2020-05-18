using System;
using System.IO;
using System.Text;
using System.Timers;
/*
본 App 동작설명
    최초는 내가 커밋하고싶어서 일부로 고치지않는이상 안일어나야한다(사용자에게 선택권을 줘야함)
# 2nd round는 무조건 커밋 
#기능 #UI
Todo:
    #     
    1.암것도안함(이것도테스트필요)     
    2 git hub file정리 -> 코드 정리
    3 다른 application 1 .playlist batch(구독자 update)
    4 git 정리 + 밑에할차례?
        git rebase HEAD~9 -i
        git push --force
    5 기능향상: file이용? tick간격조정? commit이름 바꾸기->  EMAIL?, (제자리 출력? -> 한번더 멈춘현상발생시)
    6 release note    
Release note
    C#화
*/
namespace gitA
{
    class Program
    {
        // 읽어올 text file 의 경로를 지정 합니다.
        static readonly int roundMax    = 19;
        static readonly int work        = 320;
        static readonly int tick        = 11;        
        static readonly int RANDOM_MAX  = 4 * 60 + 48 + 1;//real mode
        //static readonly int RANDOM_MAX = 2;// for test

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
            Console.WriteLine("Press Enter to exit");
                        
            timerTick.Interval = 1000 * tick; // 단위 milisec
            timerTick.Elapsed += new ElapsedEventHandler(Timer_Tick);
            timerTick.Start();

            Console.ReadLine();
        }

        static void RunGit()
        {
            string sTime = DateTime.Now.ToString("_HH:mm:ss");

            Console.WriteLine("Round {0}--------------------------------",round);

            RunCommand("git status");
            RunCommand("git commit --all -m csharp_v0_r" + Convert.ToString(round) + sTime);
            RunCommand("git push");
                        
            if (round == roundMax)
            {
                Console.WriteLine("사고방지용 안전히 종료");
                Environment.Exit(0);
            }
            round++;

            Random r = new Random();
            int randomResult = r.Next(1, RANDOM_MAX + 1);  
            //int randomResult = r.Next(1, 3 + 1);      
            

            // 알람 타이머 생성 및 시작
            if (myTimer != null)
                myTimer.Dispose();

            myTimer = new System.Threading.Timer(Timer_Elapsed, null, 1000 * randomResult * 60, 60*1000*3);

            DateTime now = DateTime.Now;
            sTime = now.ToString("HH:mm:ss");
            
            Console.WriteLine("현재시간={0}", sTime);
            DateTime target = now.AddMinutes(randomResult);
            Console.WriteLine("randomResult {0}/{1},{0}분후=>{2}", randomResult, RANDOM_MAX, target);            
        }

        private static void Timer_Elapsed(object state)
        {
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

        //static void Timer_Elapsed(object sender, ElapsedEventArgs e)
        static void Timer_Elapsed()
        {
        
        }
    }
}
