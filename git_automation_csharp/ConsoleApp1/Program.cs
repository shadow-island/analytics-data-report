using System;
using System.IO;
using System.Text;
using System.Timers;

/* 본 App 동작설명
    최초는 commit없음: 내가 커밋하고싶어서 일부로 고치지 않는이상 안일어나야한다(test시용이)
        (사용자에게 선택권을 줘야함)
        commit 강제로하려면 log숫자 초기화~
    2nd round는 무조건 커밋 
#기능 #UI
Todo:
    0. com고치기	
    0. 평일은:이제 office컴 연결시만,즉근무시간에만 coding작업할것
		* 근무시간 또는 매일 1회->1/11
		* 멈췄을때 1/5	
    1  하루 exe했으면 그다음날 exe update없이 얼마나 commit일어나는지 보자(일일 commit개수 줄여보기)
		1-1 1/5->암것도안함 (이것도테스트필요)   
        1-2기능향상:                  
		    매번:
		        - 수도추가: (새것 들어온후?)
                - "" 일때 -> command( 등)
			=> 파일에는 실제 시작 기입 시간+target  log에 분단위까지 적고
            -> commit에는 시간으로 해서 2.20(1시간뒤에확인하면되니 괜찮을듯?)
			=> 앞round숫자 스페인어로?					
			* 종료시 EMAIL?  -> later하루에 1-2개씩 commit일때만 email?
			
			후순위:			
            * 출력멈춤현상(일단매번 cmd여는걸로)-> 제자리 출력? <- 한번더 멈춘현상발생시)
		    * 안중요:=> ini file, ini file 숫자증가만? file이용 = RANDOM_MAX 조정? 		    
            * exe check필요할듯 -exe빠지는경우 있음 update표시?    
        1-3 1)release note 2)코드 정리
            이후 build할것 
        
		1-4 git 정리 + //하기전에 숫자바꾸고 저장함? 1/3할차례?            
            git rebase HEAD~16 -i 
            git push --force(이것도됨)
            git push origin master --force(필요)
        
            remote컴에서는 git reset HEAD~1 --hard로 후퇴한후 다시 git pull한다
            또는 gitk에서 hard로
            rebase하는 명령어찾기
		
            https://superuser.com/questions/273172/how-do-i-reset-master-to-origin-master
		
    2 이건 studio열지않고, 다른 application?(
		quiz 맞은거 random숫자조정으로 잘안나오게!->정치or투자)
		미린 지리-> 엑셀 -> javascript?
    
Release note    
    2021.4.19   시간에서0빼기, Force Mode:office용 한줄로 처리 , from(조사)추가, 1전체소문자로.2첫자대문자(default)
    2021.4      강제시작 옵션만들기 eu, 0이라 commit안되는경우있었다, 
    2021.       다음시간표시, Random종료기능, home위치확인(file식으로 쉽게), random화(command,수도), 
    2020.5.12   C#화함
    2020.2.12   python버전 시작
*/
namespace gitA
{
    class Program
    {
        // 읽어올 text file 의 경로를 지정 합니다
        static readonly string  fileGit = "eukm.log";
        static readonly int     WORK          = 418;
        static          int     randomStopMax = 13;
        static readonly int     roundMax      = 21;
        static          int     tick          = 21;         //초에 한번씩 찍기
        static          int     RANDOM_MAX    = 6 * 60 + 1; //일일 commit개수 줄여보기 -> 1시간단위
        static readonly bool    debuggingMode = false;      //real mode true false    

        // global
        static int round = 0;
        // timer 2개 
        static readonly Timer timerTick = new System.Timers.Timer();
        static System.Threading.Timer myTimer = null;          

        static void Main(string[] args)
        {                        

            if (debuggingMode)
            {
                randomStopMax = 1;
                tick = 1; //초에 한번씩 찍기
                RANDOM_MAX = 1;// for test        
            } //debugging mode    


            //var info = new FileInfo(fileGit);
            //if (info.LastWriteTime.Day != DateTime.Now.Day 
            // Console.WriteLine("하루지나!"); force모드 생겨 딱히 필요없을듯
            int argsCount = args.Length;
            if (argsCount >= 1)
            {
                string inputFile = args[0];
                Console.WriteLine("Force Mode: {0}", inputFile);
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
            // Junbi
            string sLocation = "";
            //FileInfo.Exists로 파일 존재유무 확인 "
            FileInfo fi = new FileInfo("gc_home.cfg");            
            if (fi.Exists)
                sLocation = "[home] ";

            Random random = new Random();
            int i; //for random

            string[] mingling = new string[] {"", "Command","Commit","Squash", "Update", "New" };
            i = random.Next(0, mingling.Length);
            string sMingling = mingling[i];
            int c = random.Next(0, 2);
            if (c == 0)
            {
                sMingling = sMingling.ToLower();
            }

            string[] cong = new string[] { "", "from", "in", "by", "of" };
            i = random.Next(0, cong.Length);
            string sCong = " " + cong[i] + " ";            

            // https://en.wikipedia.org/wiki/List_of_countries_by_GDP_(nominal)
            string[] capital = new string[] 
                {"GushavApp","Eugene",
                "Nigeria","Abuja","Kazakhstan","Nur Sultan","Slovakia","Bratislava","Puerto Rico","San Juan",
                "Dominican Republic","Santo Domingo","Guatemala","Guatemala City","Myanmar","Naypyidaw",
                "Ivory Coast","Yamoussoukro","Angola","Luanda"};

            i = random.Next(0, capital.Length);
            string sCapital = capital[i] + " ";

            //round
            round++;
            Console.WriteLine("Round {0} try--------------------------------", round);
            Console.WriteLine("작업분ver{0}", WORK);
            //

            // random Target
            DateTime now = DateTime.Now;
            string sTime = now.ToString("HH:mm:ss");            
            int randomResult = random.Next(1, RANDOM_MAX + 1);            
            DateTime target = now.AddMinutes(randomResult);
            string sTarget = target.ToString(".H.m");

            //sGoStop
            int randomStop = random.Next(1, randomStopMax + 1);
            if (round != 1 && randomStop == 1)
            {
                sTarget = "RandomStop!!!!";
            }            

            RunCommand("git pull");
            RunCommand("git status");
            RunCommand("git commit --all -m " 
                + "\"" + sLocation + sMingling + sCong + sCapital + Convert.ToString(round) + sTarget + "\"");

            RunCommand("git push");
            
            Console.Write("randomStop={0}/{1} ", randomStop, randomStopMax);            

            if (round != 1 && randomStop == 1)
            {
                Console.WriteLine("현재시간={0}", sTime);
                Console.WriteLine("사고방지용 Random 종료");
                Environment.Exit(0);
            }

            if (round >= roundMax)
            {
                Console.WriteLine("현재시간={0}", sTime);
                Console.WriteLine("사고방지용 Max 종료");
                Environment.Exit(0);
            }

            // run next round
            Console.WriteLine("현재시간={3} => {0}/{1} => {2}", randomResult, RANDOM_MAX, target, sTime);
            Console.WriteLine("in Round {0}--------------------------------", round);

            // 알람 타이머 생성 및 시작
            myTimer = new System.Threading.Timer(Timer_Elapsed, null, 1000 * randomResult * 60, 60 * 1000 * 3);
           
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

            int iNum = 0;
            string textNum;
            FileInfo fi = new FileInfo(fileGit);
            //FileInfo.Exists로 파일 존재유무 확인 "
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
            Console.WriteLine("Updating git file value================={0}", textNum);
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