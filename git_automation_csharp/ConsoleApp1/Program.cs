using System;
using System.IO;
using System.Text;
using System.Timers;

namespace gitA
{
    class Program
    {
        // 읽어올 text file 의 경로를 지정 합니다.
        static readonly int work        = 309;
        static readonly int tick        = 7;
        static readonly int roundMax    = 19;
        //static readonly int RANDOM_MAX  = 4 * 60 + 48 + 1;//48
        static readonly int RANDOM_MAX = 2 + 1;//48

        static readonly string fileGit = "eukm.log";
        static int round = 1;        
        static readonly Timer timerTick = new System.Timers.Timer();
        static Timer timerGit = new System.Timers.Timer();

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
            int randomResult = r.Next(1, RANDOM_MAX);  
            //int randomResult = r.Next(1, 3 + 1);      
            Console.WriteLine("randomResult {0}/{1}", randomResult, RANDOM_MAX);

            // 알람 타이머 생성 및 시작
            int m = randomResult;
            timerGit.Stop();
            timerGit.Interval = 1000 * m * 60;
            timerGit.Elapsed += new ElapsedEventHandler(Timer_Elapsed);
            timerGit.Start();

            sTime = DateTime.Now.ToString("HH:mm:ss");
            Console.WriteLine("현재시간={0}", sTime);
            Console.WriteLine("{0}분후...", m);
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
            Console.WriteLine("\ngit file================={0}", textValue);
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

        static void Timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            timerTick.Stop();
            Update();
            RunGit();
            timerTick.Start();
        }
    }
}
